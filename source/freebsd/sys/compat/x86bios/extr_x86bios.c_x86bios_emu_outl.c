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
typedef  int uint32_t ;
typedef  int uint16_t ;
struct x86emu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  iodev_write_1 (int,int) ; 
 int /*<<< orphan*/  iodev_write_2 (int,int) ; 
 int /*<<< orphan*/  iodev_write_4 (int,int) ; 

__attribute__((used)) static void
x86bios_emu_outl(struct x86emu *emu, uint16_t port, uint32_t val)
{

#ifndef X86BIOS_NATIVE_ARCH
	if (port >= 0x80 && port < 0x88) /* POST status register */
		return;

	if ((port & 1) != 0) {
		iodev_write_1(port, val);
		iodev_write_2(port + 1, val >> 8);
		iodev_write_1(port + 3, val >> 24);
	} else if ((port & 2) != 0) {
		iodev_write_2(port, val);
		iodev_write_2(port + 2, val >> 16);
	} else
#endif
	iodev_write_4(port, val);
}