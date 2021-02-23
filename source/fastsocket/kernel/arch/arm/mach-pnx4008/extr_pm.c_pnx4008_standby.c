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

/* Variables and functions */
 scalar_t__ SRAM_VA ; 
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  flush_cache_all () ; 
 int /*<<< orphan*/  local_fiq_disable () ; 
 int /*<<< orphan*/  local_fiq_enable () ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 int /*<<< orphan*/  memcpy (void*,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pll4_clk ; 
 void* pnx4008_cpu_standby ; 
 int /*<<< orphan*/  pnx4008_cpu_standby_sz ; 
 void* saved_sram ; 

__attribute__((used)) static inline void pnx4008_standby(void)
{
	void (*pnx4008_cpu_standby_ptr) (void);

	local_irq_disable();
	local_fiq_disable();

	clk_disable(pll4_clk);

	/*saving portion of SRAM to be used by suspend function. */
	memcpy(saved_sram, (void *)SRAM_VA, pnx4008_cpu_standby_sz);

	/*make sure SRAM copy gets physically written into SDRAM.
	   SDRAM will be placed into self-refresh during power down */
	flush_cache_all();

	/*copy suspend function into SRAM */
	memcpy((void *)SRAM_VA, pnx4008_cpu_standby, pnx4008_cpu_standby_sz);

	/*do suspend */
	pnx4008_cpu_standby_ptr = (void *)SRAM_VA;
	pnx4008_cpu_standby_ptr();

	/*restoring portion of SRAM that was used by suspend function */
	memcpy((void *)SRAM_VA, saved_sram, pnx4008_cpu_standby_sz);

	clk_enable(pll4_clk);

	local_fiq_enable();
	local_irq_enable();
}