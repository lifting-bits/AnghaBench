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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int EXIT_SUCCESS ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 char* progname ; 
 int /*<<< orphan*/ * stderr ; 
 int /*<<< orphan*/ * stdout ; 

void usage(int status)
{
	FILE *stream = (status != EXIT_SUCCESS) ? stderr : stdout;

	fprintf(stream, "Usage: %s [OPTIONS...]\n", progname);
	fprintf(stream,
"\n"
"Options:\n"
"  -B <board>       create image for the board specified with <board>\n"
"  -i <file>        read input from the file <file>\n"
"  -o <file>        write output to the file <file>\n"
"  -v <version>     set image version to <version>\n"
"  -r <region>      set image region to <region>\n"
"  -R <rootfs_size> set RootfsSize to <rootfs_size>\n"
"  -K <kernel_size> set KernelSize to <kernel_size>\n"
"  -h               show this screen\n"
	);

	exit(status);
}