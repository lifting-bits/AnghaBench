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
struct test {int dummy; } ;
struct rtprio {scalar_t__ prio; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  EPERM ; 
 int /*<<< orphan*/  RTP_PRIO_IDLE ; 
 int /*<<< orphan*/  RTP_SET ; 
 int /*<<< orphan*/  expect (char*,int,int,int /*<<< orphan*/ ) ; 
 int rtprio (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct rtprio*) ; 

void
priv_sched_rtprio_myproc_idle(int asroot, int injail, struct test *test)
{
	struct rtprio rtp;
	int error;

	rtp.type = RTP_PRIO_IDLE;
	rtp.prio = 0;
	error = rtprio(RTP_SET, 0, &rtp);
	if (asroot && injail)
		expect("priv_sched_rtprio_myproc_idle(asroot, injail)",
		    error, -1, EPERM);
	if (asroot && !injail)
		expect("priv_sched_rtprio_myproc_idle(asroot, !injail)",
		    error, 0, 0);
	if (!asroot && injail)
		expect("priv_sched_rtprio_myproc_idle(!asroot, injail)",
		    error, -1, EPERM);
	if (!asroot && !injail)
		expect("priv_sched_rtprio_myproc_idle(!asroot, !injail)",
		    error, -1, EPERM);
}