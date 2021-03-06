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
typedef  union perf_event {int dummy; } perf_event ;
typedef  int /*<<< orphan*/  u64 ;
struct perf_session {int dummy; } ;
typedef  int /*<<< orphan*/  s64 ;

/* Variables and functions */
 int /*<<< orphan*/  perf_session__process_event (struct perf_session*,union perf_event*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static s64 process_simple(struct perf_session *session,
			  union perf_event *event,
			  u64 file_offset)
{
	return perf_session__process_event(session, event, file_offset);
}