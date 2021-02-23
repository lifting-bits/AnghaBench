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
typedef  int /*<<< orphan*/  uint64_t ;
struct strbuf {int dummy; } ;

/* Variables and functions */
 struct strbuf STRBUF_INIT ; 
 int /*<<< orphan*/  perf_io_write_fl (char const*,int,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct strbuf*) ; 
 int /*<<< orphan*/  strbuf_addf (struct strbuf*,char*,int,int,int) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 

__attribute__((used)) static void fn_child_exit_fl(const char *file, int line,
			     uint64_t us_elapsed_absolute, int cid, int pid,
			     int code, uint64_t us_elapsed_child)
{
	const char *event_name = "child_exit";
	struct strbuf buf_payload = STRBUF_INIT;

	strbuf_addf(&buf_payload, "[ch%d] pid:%d code:%d", cid, pid, code);

	perf_io_write_fl(file, line, event_name, NULL, &us_elapsed_absolute,
			 &us_elapsed_child, NULL, &buf_payload);
	strbuf_release(&buf_payload);
}