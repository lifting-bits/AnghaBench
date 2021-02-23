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
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  bcm47xx_wdt_busy ; 
 int /*<<< orphan*/  bcm47xx_wdt_start () ; 
 int nonseekable_open (struct inode*,struct file*) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int bcm47xx_wdt_open(struct inode *inode, struct file *file)
{
	if (test_and_set_bit(0, &bcm47xx_wdt_busy))
		return -EBUSY;

	bcm47xx_wdt_start();
	return nonseekable_open(inode, file);
}