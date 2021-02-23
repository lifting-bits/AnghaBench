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
struct stat {scalar_t__ st_size; } ;

/* Variables and functions */
 int /*<<< orphan*/  assertion_count (char const*,int) ; 
 int /*<<< orphan*/  failure_finish (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  failure_start (char const*,int,char*,char const*) ; 
 scalar_t__ stat (char const*,struct stat*) ; 

int
assertion_non_empty_file(const char *filename, int line, const char *f1)
{
	struct stat st;

	assertion_count(filename, line);

	if (stat(f1, &st) != 0) {
		failure_start(filename, line, "Stat failed: %s", f1);
		failure_finish(NULL);
		return (0);
	}
	if (st.st_size == 0) {
		failure_start(filename, line, "File empty: %s", f1);
		failure_finish(NULL);
		return (0);
	}
	return (1);
}