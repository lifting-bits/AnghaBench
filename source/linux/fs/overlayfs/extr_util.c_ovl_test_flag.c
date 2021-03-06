#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct inode {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 TYPE_1__* OVL_I (struct inode*) ; 
 int test_bit (unsigned long,int /*<<< orphan*/ *) ; 

bool ovl_test_flag(unsigned long flag, struct inode *inode)
{
	return test_bit(flag, &OVL_I(inode)->flags);
}