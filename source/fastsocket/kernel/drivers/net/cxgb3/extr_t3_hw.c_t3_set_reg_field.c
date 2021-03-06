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
struct adapter {int dummy; } ;

/* Variables and functions */
 int t3_read_reg (struct adapter*,unsigned int) ; 
 int /*<<< orphan*/  t3_write_reg (struct adapter*,unsigned int,int) ; 

void t3_set_reg_field(struct adapter *adapter, unsigned int addr, u32 mask,
		      u32 val)
{
	u32 v = t3_read_reg(adapter, addr) & ~mask;

	t3_write_reg(adapter, addr, v | val);
	t3_read_reg(adapter, addr);	/* flush */
}