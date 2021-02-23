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
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  __module_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ibwdt_is_open ; 
 int /*<<< orphan*/  ibwdt_ping () ; 
 int nonseekable_open (struct inode*,struct file*) ; 
 scalar_t__ nowayout ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ibwdt_open(struct inode *inode, struct file *file)
{
	if (test_and_set_bit(0, &ibwdt_is_open))
		return -EBUSY;
	if (nowayout)
		__module_get(THIS_MODULE);

	/* Activate */
	ibwdt_ping();
	return nonseekable_open(inode, file);
}