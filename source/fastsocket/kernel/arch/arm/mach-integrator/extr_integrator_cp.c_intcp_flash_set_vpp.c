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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  CINTEGRATOR_FLASHPROG_FLVPPEN ; 
 scalar_t__ INTCP_FLASHPROG ; 
 scalar_t__ INTCP_VA_CTRL_BASE ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void intcp_flash_set_vpp(int on)
{
	u32 val;

	val = readl(INTCP_VA_CTRL_BASE + INTCP_FLASHPROG);
	if (on)
		val |= CINTEGRATOR_FLASHPROG_FLVPPEN;
	else
		val &= ~CINTEGRATOR_FLASHPROG_FLVPPEN;
	writel(val, INTCP_VA_CTRL_BASE + INTCP_FLASHPROG);
}