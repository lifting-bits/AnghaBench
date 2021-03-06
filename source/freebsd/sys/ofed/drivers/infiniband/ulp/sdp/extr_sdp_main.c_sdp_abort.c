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
struct socket {int dummy; } ;
struct sdp_sock {int flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  ECONNABORTED ; 
 int /*<<< orphan*/  KASSERT (int,char*) ; 
 int SDP_DROPPED ; 
 int SDP_TIMEWAIT ; 
 int /*<<< orphan*/  SDP_WLOCK (struct sdp_sock*) ; 
 int /*<<< orphan*/  SDP_WUNLOCK (struct sdp_sock*) ; 
 int /*<<< orphan*/  sdp_drop (struct sdp_sock*,int /*<<< orphan*/ ) ; 
 struct sdp_sock* sdp_sk (struct socket*) ; 

void
sdp_abort(struct socket *so)
{
	struct sdp_sock *ssk;

	ssk = sdp_sk(so);
	SDP_WLOCK(ssk);
	/*
	 * If we have not yet dropped, do it now.
	 */
	if (!(ssk->flags & SDP_TIMEWAIT) &&
	    !(ssk->flags & SDP_DROPPED))
		sdp_drop(ssk, ECONNABORTED);
	KASSERT(ssk->flags & SDP_DROPPED, ("sdp_abort: %p not dropped 0x%X",
	    ssk, ssk->flags));
	SDP_WUNLOCK(ssk);
}