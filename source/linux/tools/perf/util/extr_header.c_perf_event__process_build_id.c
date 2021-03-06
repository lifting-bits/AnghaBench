#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  filename; } ;
union perf_event {TYPE_1__ build_id; } ;
struct perf_session {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __event_process_build_id (TYPE_1__*,int /*<<< orphan*/ ,struct perf_session*) ; 

int perf_event__process_build_id(struct perf_session *session,
				 union perf_event *event)
{
	__event_process_build_id(&event->build_id,
				 event->build_id.filename,
				 session);
	return 0;
}