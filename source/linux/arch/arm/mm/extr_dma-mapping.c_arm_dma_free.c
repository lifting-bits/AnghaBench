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
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  __arm_dma_free (struct device*,size_t,void*,int /*<<< orphan*/ ,unsigned long,int) ; 

void arm_dma_free(struct device *dev, size_t size, void *cpu_addr,
		  dma_addr_t handle, unsigned long attrs)
{
	__arm_dma_free(dev, size, cpu_addr, handle, attrs, false);
}