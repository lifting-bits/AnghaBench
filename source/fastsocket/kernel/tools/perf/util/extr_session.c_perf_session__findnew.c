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
struct thread {int dummy; } ;
struct perf_session {int /*<<< orphan*/  host_machine; } ;
typedef  int /*<<< orphan*/  pid_t ;

/* Variables and functions */
 struct thread* machine__findnew_thread (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

struct thread *perf_session__findnew(struct perf_session *session, pid_t pid)
{
	return machine__findnew_thread(&session->host_machine, pid);
}