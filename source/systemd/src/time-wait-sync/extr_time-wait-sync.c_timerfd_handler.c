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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  sd_event_source ;
typedef  int /*<<< orphan*/  ClockState ;

/* Variables and functions */
 int clock_state_update (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sd_event_source_get_event (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int timerfd_handler(sd_event_source *s,
                           int fd,
                           uint32_t revents,
                           void *userdata) {
        ClockState *sp = userdata;

        return clock_state_update(sp, sd_event_source_get_event(s));
}