#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_2__ {int /*<<< orphan*/ * _8; } ;
struct oxygen {TYPE_1__ saved_registers; scalar_t__ addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,scalar_t__) ; 

void oxygen_write8(struct oxygen *chip, unsigned int reg, u8 value)
{
	outb(value, chip->addr + reg);
	chip->saved_registers._8[reg] = value;
}