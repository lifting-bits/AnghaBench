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
 int /*<<< orphan*/  args ; 
 int /*<<< orphan*/  commands ; 
 int /*<<< orphan*/  context ; 
 int /*<<< orphan*/  errx (int,char*,int) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 scalar_t__ getarg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char**,int*) ; 
 scalar_t__ help_flag ; 
 int /*<<< orphan*/  hx509_context_free (int /*<<< orphan*/ *) ; 
 int hx509_context_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hx509_query_statistic_file (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  num_args ; 
 int /*<<< orphan*/  print_version (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  setprogname (char*) ; 
 int sl_command (int /*<<< orphan*/ ,int,char**) ; 
 scalar_t__ stat_file_string ; 
 int /*<<< orphan*/  usage (int) ; 
 scalar_t__ version_flag ; 
 int /*<<< orphan*/  warnx (char*,char*) ; 

int
main(int argc, char **argv)
{
    int ret, optidx = 0;

    setprogname (argv[0]);

    if(getarg(args, num_args, argc, argv, &optidx))
	usage(1);
    if(help_flag)
	usage(0);
    if(version_flag) {
	print_version(NULL);
	exit(0);
    }
    argv += optidx;
    argc -= optidx;

    if (argc == 0)
	usage(1);

    ret = hx509_context_init(&context);
    if (ret)
	errx(1, "hx509_context_init failed with %d", ret);

    if (stat_file_string)
	hx509_query_statistic_file(context, stat_file_string);

    ret = sl_command(commands, argc, argv);
    if(ret == -1)
	warnx ("unrecognized command: %s", argv[0]);

    hx509_context_free(&context);

    return ret;
}