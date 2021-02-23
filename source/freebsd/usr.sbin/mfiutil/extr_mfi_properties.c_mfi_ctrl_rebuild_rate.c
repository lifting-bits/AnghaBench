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
struct mfi_ctrl_props {int rebuild_rate; } ;

/* Variables and functions */
 int /*<<< orphan*/  O_RDWR ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  close (int) ; 
 int errno ; 
 int mfi_ctrl_get_properties (int,struct mfi_ctrl_props*) ; 
 int mfi_ctrl_set_properties (int,struct mfi_ctrl_props*) ; 
 int mfi_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mfi_unit ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  warn (char*) ; 

__attribute__((used)) static int
mfi_ctrl_rebuild_rate(int ac, char **av)
{
	int error, fd;
	struct mfi_ctrl_props ctrl_props;

	if (ac > 2) {
		warn("mfi_ctrl_set_rebuild_rate");
		return(-1);
	}
		
	fd = mfi_open(mfi_unit, O_RDWR);
	if (fd < 0) {
		error = errno;
		warn("mfi_open");
		return (error);
	}

	error = mfi_ctrl_get_properties(fd, &ctrl_props);
	if ( error < 0) {
		error = errno;
		warn("Failed to get controller properties");
		close(fd);
		return (error);
	}
	/*
	 * User requested a change to the rebuild rate
	 */
	if (ac > 1) {
		ctrl_props.rebuild_rate = atoi(av[ac - 1]);
		error = mfi_ctrl_set_properties(fd, &ctrl_props);
		if ( error < 0) {
			error = errno;
			warn("Failed to set controller properties");
			close(fd);
			return (error);
		}

		error = mfi_ctrl_get_properties(fd, &ctrl_props);
		if ( error < 0) {
			error = errno;
			warn("Failed to get controller properties");
			close(fd);
			return (error);
		}
	}
	printf ("controller rebuild rate: %%%u \n",
		ctrl_props.rebuild_rate);
	return (0);
}