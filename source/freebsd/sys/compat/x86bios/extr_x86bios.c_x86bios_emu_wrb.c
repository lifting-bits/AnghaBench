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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct x86emu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/ * x86bios_get_pages (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  x86bios_set_fault (struct x86emu*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
x86bios_emu_wrb(struct x86emu *emu, uint32_t addr, uint8_t val)
{
	uint8_t *va;

	va = x86bios_get_pages(addr, sizeof(*va));
	if (va == NULL)
		x86bios_set_fault(emu, addr);

	*va = val;
}