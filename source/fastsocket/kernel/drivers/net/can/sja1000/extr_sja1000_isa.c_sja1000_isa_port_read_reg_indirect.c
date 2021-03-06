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
typedef  int /*<<< orphan*/  u8 ;
struct sja1000_priv {scalar_t__ reg_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  inb (unsigned long) ; 
 int /*<<< orphan*/  outb (int,unsigned long) ; 

__attribute__((used)) static u8 sja1000_isa_port_read_reg_indirect(const struct sja1000_priv *priv,
					     int reg)
{
	unsigned long base = (unsigned long)priv->reg_base;

	outb(reg, base);
	return inb(base + 1);
}