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
struct drm_device {TYPE_1__* pdev; } ;
struct TYPE_2__ {int device; } ;

/* Variables and functions */
 scalar_t__ nv_two_heads (struct drm_device*) ; 

__attribute__((used)) static inline bool
nv_gf4_disp_arch(struct drm_device *dev)
{
	return nv_two_heads(dev) && (dev->pdev->device & 0x0ff0) != 0x0110;
}