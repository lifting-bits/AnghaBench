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
typedef  int vm_size_t ;
typedef  int vm_offset_t ;

/* Variables and functions */
 int CACHEOP_R4K_HIT_INV ; 
 int CACHE_R4K_I ; 
 int /*<<< orphan*/  SYNC ; 
 int /*<<< orphan*/  cache_op_r4k_line (int,int) ; 
 int /*<<< orphan*/  cache_r4k_op_32lines_64 (int,int) ; 
 int /*<<< orphan*/  mips_intern_dcache_wb_range (int,int) ; 
 int round_line64 (int) ; 
 int trunc_line64 (int) ; 

void
mipsNN_icache_sync_range_64(vm_offset_t va, vm_size_t size)
{
	vm_offset_t eva;

	eva = round_line64(va + size);
	va = trunc_line64(va);

	mips_intern_dcache_wb_range(va, (eva - va));

	while ((eva - va) >= (32 * 64)) {
		cache_r4k_op_32lines_64(va, CACHE_R4K_I|CACHEOP_R4K_HIT_INV);
		va += (32 * 64);
	}

	while (va < eva) {
		cache_op_r4k_line(va, CACHE_R4K_I|CACHEOP_R4K_HIT_INV);
		va += 64;
	}

	SYNC;
}