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
struct file {int dummy; } ;

/* Variables and functions */
 long video_usercopy (struct file*,unsigned int,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  w9966_v4l_do_ioctl ; 

__attribute__((used)) static long w9966_v4l_ioctl(struct file *file,
			   unsigned int cmd, unsigned long arg)
{
	return video_usercopy(file, cmd, arg, w9966_v4l_do_ioctl);
}