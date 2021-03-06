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
struct i2c_msg {int addr; int flags; } ;

/* Variables and functions */
 int I2C_M_TEN ; 

__attribute__((used)) static inline int iic_invalid_address(const struct i2c_msg* p)
{
	return (p->addr > 0x3ff) || (!(p->flags & I2C_M_TEN) && (p->addr > 0x7f));
}