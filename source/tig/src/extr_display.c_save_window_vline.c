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
typedef  int /*<<< orphan*/  WINDOW ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int ERR ; 
 scalar_t__ fprintf (int /*<<< orphan*/ *,char*,char*) ; 
 int mvwinnstr (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,char*,size_t) ; 
 char* string_trim_end (char*) ; 
 scalar_t__ strlen (char*) ; 

__attribute__((used)) static bool
save_window_vline(FILE *file, WINDOW *left, WINDOW *right, int y, char *buf, size_t bufsize)
{
	int read1 = mvwinnstr(left, y, 0, buf, bufsize);
	int read2 = read1 == ERR ? ERR : mvwinnstr(right, y, 0, buf + read1 + 1, bufsize - read1 - 1);

	if (read2 == ERR)
		return false;
	buf[read1] = '|';
	buf = string_trim_end(buf);

	return fprintf(file, "%s\n", string_trim_end(buf)) == strlen(buf) + 1;
}