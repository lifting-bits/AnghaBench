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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct nvbios_init {scalar_t__ offset; struct nouveau_bios* bios; } ;
struct nouveau_bios {int dummy; } ;

/* Variables and functions */
 int init_rdauxr (struct nvbios_init*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_wrauxr (struct nvbios_init*,int /*<<< orphan*/ ,int) ; 
 int nv_ro08 (struct nouveau_bios*,scalar_t__) ; 
 int /*<<< orphan*/  nv_ro32 (struct nouveau_bios*,scalar_t__) ; 
 int /*<<< orphan*/  trace (char*,int /*<<< orphan*/ ,int,...) ; 

__attribute__((used)) static void
init_auxch(struct nvbios_init *init)
{
	struct nouveau_bios *bios = init->bios;
	u32 addr = nv_ro32(bios, init->offset + 1);
	u8 count = nv_ro08(bios, init->offset + 5);

	trace("AUXCH\tAUX[0x%08x] 0x%02x\n", addr, count);
	init->offset += 6;

	while (count--) {
		u8 mask = nv_ro08(bios, init->offset + 0);
		u8 data = nv_ro08(bios, init->offset + 1);
		trace("\tAUX[0x%08x] &= 0x%02x |= 0x%02x\n", addr, mask, data);
		mask = init_rdauxr(init, addr) & mask;
		init_wrauxr(init, addr, mask | data);
		init->offset += 2;
	}
}