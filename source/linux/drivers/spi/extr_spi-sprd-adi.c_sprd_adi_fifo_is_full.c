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
struct sprd_adi {scalar_t__ base; } ;

/* Variables and functions */
 int BIT_FIFO_FULL ; 
 scalar_t__ REG_ADI_ARM_FIFO_STS ; 
 int readl_relaxed (scalar_t__) ; 

__attribute__((used)) static int sprd_adi_fifo_is_full(struct sprd_adi *sadi)
{
	return readl_relaxed(sadi->base + REG_ADI_ARM_FIFO_STS) & BIT_FIFO_FULL;
}