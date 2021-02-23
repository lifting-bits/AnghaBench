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

/* Variables and functions */
 int /*<<< orphan*/  FE_REG_FE_INT_ENABLE ; 
 int fe_reg_r32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fe_reg_w32 (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void fe_int_disable(u32 mask)
{
	fe_reg_w32(fe_reg_r32(FE_REG_FE_INT_ENABLE) & ~mask,
		   FE_REG_FE_INT_ENABLE);
	/* flush write */
	fe_reg_r32(FE_REG_FE_INT_ENABLE);
}