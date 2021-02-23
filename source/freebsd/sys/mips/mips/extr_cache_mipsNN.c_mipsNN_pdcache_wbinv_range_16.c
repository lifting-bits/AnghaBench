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
 int CACHEOP_R4K_HIT_WB_INV ; 
 int CACHE_R4K_D ; 
 int /*<<< orphan*/  SYNC ; 
 int /*<<< orphan*/  cache_op_r4k_line (int,int) ; 
 int /*<<< orphan*/  cache_r4k_op_32lines_16 (int,int) ; 
 int round_line16 (int) ; 
 int trunc_line16 (int) ; 

void
mipsNN_pdcache_wbinv_range_16(vm_offset_t va, vm_size_t size)
{
	vm_offset_t eva;

	eva = round_line16(va + size);
	va = trunc_line16(va);

	while ((eva - va) >= (32 * 16)) {
		cache_r4k_op_32lines_16(va,
		    CACHE_R4K_D|CACHEOP_R4K_HIT_WB_INV);
		va += (32 * 16);
	}

	while (va < eva) {
		cache_op_r4k_line(va, CACHE_R4K_D|CACHEOP_R4K_HIT_WB_INV);
		va += 16;
	}

	SYNC;
}