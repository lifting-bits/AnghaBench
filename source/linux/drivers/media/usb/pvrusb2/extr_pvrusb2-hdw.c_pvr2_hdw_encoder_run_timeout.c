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
struct timer_list {int dummy; } ;
struct pvr2_hdw {int state_encoder_runok; int state_stale; int /*<<< orphan*/  workpoll; } ;

/* Variables and functions */
 int /*<<< orphan*/  encoder_run_timer ; 
 struct pvr2_hdw* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 struct pvr2_hdw* hdw ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_stbit (char*,int) ; 

__attribute__((used)) static void pvr2_hdw_encoder_run_timeout(struct timer_list *t)
{
	struct pvr2_hdw *hdw = from_timer(hdw, t, encoder_run_timer);
	if (!hdw->state_encoder_runok) {
		hdw->state_encoder_runok = !0;
		trace_stbit("state_encoder_runok",hdw->state_encoder_runok);
		hdw->state_stale = !0;
		schedule_work(&hdw->workpoll);
	}
}