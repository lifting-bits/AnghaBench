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
struct dentry {int dummy; } ;

/* Variables and functions */
 int DCACHE_MOUNTED ; 
 scalar_t__ d_mountpoint (struct dentry*) ; 

__attribute__((used)) static int managed_d_mountpoint(struct dentry *dentry)
{
	return d_mountpoint(dentry) ? DCACHE_MOUNTED : 0;
}