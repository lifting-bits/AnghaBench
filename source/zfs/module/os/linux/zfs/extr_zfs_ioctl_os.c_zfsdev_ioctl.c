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
typedef  unsigned int uint_t ;
struct file {int dummy; } ;

/* Variables and functions */
 unsigned int ZFS_IOC_FIRST ; 
 long zfsdev_ioctl_common (unsigned int,unsigned long) ; 

__attribute__((used)) static long
zfsdev_ioctl(struct file *filp, unsigned cmd, unsigned long arg)
{
	uint_t vecnum;

	vecnum = cmd - ZFS_IOC_FIRST;
	return (zfsdev_ioctl_common(vecnum, arg));
}