#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  (* bitmap_surface_put_bits_native ) (int /*<<< orphan*/ ,void const* const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ;} ;
struct TYPE_5__ {TYPE_1__ vt; } ;
typedef  TYPE_2__ vdp_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  VdpStatus ;
typedef  int /*<<< orphan*/  VdpRect ;
typedef  int /*<<< orphan*/  VdpBitmapSurface ;

/* Variables and functions */
 int /*<<< orphan*/  BITMAP_SURFACE_PUT_BITS_NATIVE ; 
 int /*<<< orphan*/  CHECK_FUNC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,void const* const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 

VdpStatus vdp_bitmap_surface_put_bits_native(const vdp_t *vdp,
    VdpBitmapSurface surface, const void *const *data, const uint32_t *pitch,
    const VdpRect *rect)
{
    CHECK_FUNC(BITMAP_SURFACE_PUT_BITS_NATIVE);
    return vdp->vt.bitmap_surface_put_bits_native(surface, data, pitch, rect);
}