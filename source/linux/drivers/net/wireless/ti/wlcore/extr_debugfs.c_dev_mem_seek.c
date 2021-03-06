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
typedef  int loff_t ;

/* Variables and functions */
 int EINVAL ; 
 int no_seek_end_llseek (struct file*,int,int) ; 

__attribute__((used)) static loff_t dev_mem_seek(struct file *file, loff_t offset, int orig)
{
	/* only requests of dword-aligned size and offset are supported */
	if (offset % 4)
		return -EINVAL;

	return no_seek_end_llseek(file, offset, orig);
}