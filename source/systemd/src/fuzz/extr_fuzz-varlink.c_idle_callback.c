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
typedef  int /*<<< orphan*/  sd_event_source ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sd_event_exit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sd_event_source_get_event (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int idle_callback(sd_event_source *s, void *userdata) {
        assert(s);

        /* Called as idle callback when there's nothing else to do anymore */
        sd_event_exit(sd_event_source_get_event(s), 0);
        return 0;
}