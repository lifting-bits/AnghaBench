#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  sd_event_time_handler_t ;
struct TYPE_16__ {scalar_t__ description; } ;
typedef  TYPE_1__ sd_event_source ;
typedef  TYPE_1__* sd_event ;
typedef  int /*<<< orphan*/  int64_t ;
typedef  scalar_t__ clockid_t ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int SD_EVENT_OFF ; 
 int /*<<< orphan*/  SD_EVENT_ONESHOT ; 
 int /*<<< orphan*/  SYNTHETIC_ERRNO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (TYPE_1__**) ; 
 int log_debug_errno (int,char*,...) ; 
 int sd_event_add_time (TYPE_1__**,TYPE_1__**,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 int sd_event_source_get_enabled (TYPE_1__*,int*) ; 
 int sd_event_source_get_time_clock (TYPE_1__*,scalar_t__*) ; 
 int sd_event_source_set_description (TYPE_1__*,char const*) ; 
 int sd_event_source_set_enabled (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int sd_event_source_set_priority (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int sd_event_source_set_time (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int sd_event_source_set_time_accuracy (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sd_event_source_set_userdata (TYPE_1__*,void*) ; 
 char const* strna (char const*) ; 

int event_reset_time(
                sd_event *e,
                sd_event_source **s,
                clockid_t clock,
                uint64_t usec,
                uint64_t accuracy,
                sd_event_time_handler_t callback,
                void *userdata,
                int64_t priority,
                const char *description,
                bool force_reset) {

        bool created = false;
        int enabled, r;
        clockid_t c;

        assert(e);
        assert(s);

        if (*s) {
                if (!force_reset) {
                        r = sd_event_source_get_enabled(*s, &enabled);
                        if (r < 0)
                                return log_debug_errno(r, "sd-event: Failed to query whether event source \"%s\" is enabled or not: %m",
                                                       strna((*s)->description ?: description));

                        if (enabled != SD_EVENT_OFF)
                                return 0;
                }

                r = sd_event_source_get_time_clock(*s, &c);
                if (r < 0)
                        return log_debug_errno(r, "sd-event: Failed to get clock id of event source \"%s\": %m", strna((*s)->description ?: description));

                if (c != clock)
                        return log_debug_errno(SYNTHETIC_ERRNO(EINVAL),
                                               "sd-event: Current clock id %i of event source \"%s\" is different from specified one %i.",
                                               (int)c,
                                               strna((*s)->description ? : description),
                                               (int)clock);

                r = sd_event_source_set_time(*s, usec);
                if (r < 0)
                        return log_debug_errno(r, "sd-event: Failed to set time for event source \"%s\": %m", strna((*s)->description ?: description));

                r = sd_event_source_set_time_accuracy(*s, accuracy);
                if (r < 0)
                        return log_debug_errno(r, "sd-event: Failed to set accuracy for event source \"%s\": %m", strna((*s)->description ?: description));

                /* callback function is not updated, as we do not have sd_event_source_set_time_callback(). */

                (void) sd_event_source_set_userdata(*s, userdata);

                r = sd_event_source_set_enabled(*s, SD_EVENT_ONESHOT);
                if (r < 0)
                        return log_debug_errno(r, "sd-event: Failed to enable event source \"%s\": %m", strna((*s)->description ?: description));
        } else {
                r = sd_event_add_time(e, s, clock, usec, accuracy, callback, userdata);
                if (r < 0)
                        return log_debug_errno(r, "sd-event: Failed to create timer event \"%s\": %m", strna(description));

                created = true;
        }

        r = sd_event_source_set_priority(*s, priority);
        if (r < 0)
                return log_debug_errno(r, "sd-event: Failed to set priority for event source \"%s\": %m", strna((*s)->description ?: description));

        if (description) {
                r = sd_event_source_set_description(*s, description);
                if (r < 0)
                        return log_debug_errno(r, "sd-event: Failed to set description for event source \"%s\": %m", description);
        }

        return created;
}