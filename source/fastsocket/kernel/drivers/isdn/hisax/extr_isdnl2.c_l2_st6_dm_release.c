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
struct sk_buff {int dummy; } ;
struct PStack {int dummy; } ;
struct FsmInst {struct PStack* userdata; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIRM ; 
 int /*<<< orphan*/  FsmChangeState (struct FsmInst*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ST_L2_4 ; 
 scalar_t__ get_PollFlagFree (struct PStack*,struct sk_buff*) ; 
 int /*<<< orphan*/  lapb_dl_release_l2l3 (struct PStack*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stop_t200 (struct PStack*,int) ; 

__attribute__((used)) static void
l2_st6_dm_release(struct FsmInst *fi, int event, void *arg)
{
	struct PStack *st = fi->userdata;
	struct sk_buff *skb = arg;

	if (get_PollFlagFree(st, skb)) {
		stop_t200(st, 8);
		lapb_dl_release_l2l3(st, CONFIRM);
		FsmChangeState(fi, ST_L2_4);
	}
}