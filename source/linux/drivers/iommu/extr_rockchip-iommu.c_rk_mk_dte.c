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
typedef  int u32 ;
typedef  int dma_addr_t ;

/* Variables and functions */
 int RK_DTE_PT_ADDRESS_MASK ; 
 int RK_DTE_PT_VALID ; 

__attribute__((used)) static inline u32 rk_mk_dte(dma_addr_t pt_dma)
{
	return (pt_dma & RK_DTE_PT_ADDRESS_MASK) | RK_DTE_PT_VALID;
}