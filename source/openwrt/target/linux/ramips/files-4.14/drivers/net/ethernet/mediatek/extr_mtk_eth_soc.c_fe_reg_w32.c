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
typedef  enum fe_reg { ____Placeholder_fe_reg } fe_reg ;

/* Variables and functions */
 int /*<<< orphan*/ * fe_reg_table ; 
 int /*<<< orphan*/  fe_w32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void fe_reg_w32(u32 val, enum fe_reg reg)
{
	fe_w32(val, fe_reg_table[reg]);
}