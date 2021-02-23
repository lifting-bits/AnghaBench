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
typedef  int u_int32_t ;
struct cam_path {int dummy; } ;

/* Variables and functions */
#define  AC_LOST_DEVICE 128 
 int /*<<< orphan*/  xpt_print_path (struct cam_path*) ; 

__attribute__((used)) static void
ps3cdrom_async(void *callback_arg, u_int32_t code,
	struct cam_path* path, void *arg)
{
	switch (code) {
	case AC_LOST_DEVICE:
		xpt_print_path(path);
		break;
	default:
		break;
	}
}