#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct inpcb {int inp_flags; struct ifnet* inp_boundifp; } ;
struct ifnet {int if_eflags; } ;
typedef  int /*<<< orphan*/  boolean_t ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int IFEF_RESTRICTED_RECV ; 
 scalar_t__ IFNET_IS_AWDL_RESTRICTED (struct ifnet*) ; 
 scalar_t__ IFNET_IS_CELLULAR (struct ifnet*) ; 
 scalar_t__ IFNET_IS_EXPENSIVE (struct ifnet*) ; 
 scalar_t__ IFNET_IS_INTCOPROC (struct ifnet*) ; 
 int /*<<< orphan*/  INP_AWDL_UNRESTRICTED (struct inpcb*) ; 
 int INP_BOUND_IF ; 
 int /*<<< orphan*/  INP_INTCOPROC_ALLOWED (struct inpcb*) ; 
 scalar_t__ INP_NO_CELLULAR (struct inpcb*) ; 
 scalar_t__ INP_NO_EXPENSIVE (struct inpcb*) ; 
 int INP_RECV_ANYIF ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  VERIFY (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sorestrictrecv ; 

__attribute__((used)) static boolean_t
_inp_restricted_recv(struct inpcb *inp, struct ifnet *ifp)
{
	VERIFY(inp != NULL);

	/*
	 * Inbound restrictions.
	 */
	if (!sorestrictrecv)
		return (FALSE);

	if (ifp == NULL)
		return (FALSE);

	if (IFNET_IS_CELLULAR(ifp) && INP_NO_CELLULAR(inp))
		return (TRUE);

	if (IFNET_IS_EXPENSIVE(ifp) && INP_NO_EXPENSIVE(inp))
		return (TRUE);

	if (IFNET_IS_AWDL_RESTRICTED(ifp) && !INP_AWDL_UNRESTRICTED(inp))
		return (TRUE);

	if (!(ifp->if_eflags & IFEF_RESTRICTED_RECV))
		return (FALSE);

	if (inp->inp_flags & INP_RECV_ANYIF)
		return (FALSE);

	if ((inp->inp_flags & INP_BOUND_IF) && inp->inp_boundifp == ifp)
		return (FALSE);

	if (IFNET_IS_INTCOPROC(ifp) && !INP_INTCOPROC_ALLOWED(inp))
		return (TRUE);

	return (TRUE);
}