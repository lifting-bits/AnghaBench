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
struct mips_cdmm_device {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct mips_cdmm_device*) ; 
 struct mips_cdmm_device* to_mips_cdmm_device (struct device*) ; 

__attribute__((used)) static void mips_cdmm_release(struct device *dev)
{
	struct mips_cdmm_device *cdev = to_mips_cdmm_device(dev);

	kfree(cdev);
}