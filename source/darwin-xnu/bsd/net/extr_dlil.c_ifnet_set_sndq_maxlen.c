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
typedef  int /*<<< orphan*/  u_int32_t ;
struct ifnet {int if_eflags; int /*<<< orphan*/  if_snd; } ;
typedef  int /*<<< orphan*/  errno_t ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENXIO ; 
 int IFEF_TXSTART ; 
 int /*<<< orphan*/  ifclassq_set_maxlen (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

errno_t
ifnet_set_sndq_maxlen(struct ifnet *ifp, u_int32_t maxqlen)
{
	if (ifp == NULL)
		return (EINVAL);
	else if (!(ifp->if_eflags & IFEF_TXSTART))
		return (ENXIO);

	ifclassq_set_maxlen(&ifp->if_snd, maxqlen);

	return (0);
}