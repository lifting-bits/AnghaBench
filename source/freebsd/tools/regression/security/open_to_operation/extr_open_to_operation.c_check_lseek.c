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

/* Variables and functions */
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  close (int) ; 
 int lseek (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  notok_mode (char const*,char*,int) ; 
 int /*<<< orphan*/  ok_mode (char const*,int /*<<< orphan*/ *,int) ; 
 int open (char const*,int) ; 

__attribute__((used)) static void
check_lseek(const char *testname, const char *path, const int *modes,
    int modes_count)
{
	int fd, i, mode;

	/*
	 * lseek() should work regardless of open mode.
	 */
	for (i = 0; i < modes_count; i++) {
		mode = modes[i];
		fd = open(path, mode);
		if (fd < 0) {
			notok_mode(testname, "open", mode);
			continue;
		}
		if (lseek(fd, 100, SEEK_SET) == 100)
			ok_mode(testname, NULL, mode);
		else
			notok_mode(testname, "failed", mode);
		close(fd);
	}
}