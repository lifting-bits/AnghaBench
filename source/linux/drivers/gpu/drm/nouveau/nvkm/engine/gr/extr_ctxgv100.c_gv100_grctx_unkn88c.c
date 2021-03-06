#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct nvkm_device {int dummy; } ;
struct TYPE_4__ {struct nvkm_device* device; } ;
struct TYPE_5__ {TYPE_1__ subdev; } ;
struct TYPE_6__ {TYPE_2__ engine; } ;
struct gf100_gr {TYPE_3__ base; } ;

/* Variables and functions */
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int const,int const) ; 
 int /*<<< orphan*/  nvkm_rd32 (struct nvkm_device*,int) ; 

__attribute__((used)) static void
gv100_grctx_unkn88c(struct gf100_gr *gr, bool on)
{
	struct nvkm_device *device = gr->base.engine.subdev.device;
	const u32 mask = 0x00000010, data = on ? mask : 0x00000000;
	nvkm_mask(device, 0x40988c, mask, data);
	nvkm_rd32(device, 0x40988c);
	nvkm_mask(device, 0x41a88c, mask, data);
	nvkm_rd32(device, 0x41a88c);
	nvkm_mask(device, 0x408a14, mask, data);
	nvkm_rd32(device, 0x408a14);
}