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
struct snd_ice1712 {int /*<<< orphan*/  vt1720; } ;

/* Variables and functions */
 int /*<<< orphan*/  GPIO_WRITE_MASK ; 
 int /*<<< orphan*/  GPIO_WRITE_MASK_22 ; 
 int /*<<< orphan*/  ICEREG1724 (struct snd_ice1712*,int /*<<< orphan*/ ) ; 
 scalar_t__ inb (int /*<<< orphan*/ ) ; 
 unsigned int inw (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int snd_vt1724_get_gpio_mask(struct snd_ice1712 *ice)
{
	unsigned int mask;
	if (!ice->vt1720)
		mask = (unsigned int)inb(ICEREG1724(ice, GPIO_WRITE_MASK_22));
	else
		mask = 0;
	mask = (mask << 16) | inw(ICEREG1724(ice, GPIO_WRITE_MASK));
	return mask;
}