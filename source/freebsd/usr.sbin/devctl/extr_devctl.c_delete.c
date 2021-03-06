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
 int /*<<< orphan*/  delete_usage () ; 
 scalar_t__ devctl_delete (char*,int) ; 
 int /*<<< orphan*/  err (int,char*,char*) ; 
 int getopt (int,char**,char*) ; 
 scalar_t__ optind ; 

__attribute__((used)) static int
delete(int ac, char **av)
{
	bool force;
	int ch;

	force = false;
	while ((ch = getopt(ac, av, "f")) != -1)
		switch (ch) {
		case 'f':
			force = true;
			break;
		default:
			delete_usage();
		}
	ac -= optind;
	av += optind;

	if (ac != 1)
		delete_usage();
	if (devctl_delete(av[0], force) < 0)
		err(1, "Failed to delete %s", av[0]);
	return (0);
}