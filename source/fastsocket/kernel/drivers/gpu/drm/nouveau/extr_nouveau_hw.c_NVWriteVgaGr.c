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
struct drm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  NVWritePRMVIO (struct drm_device*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NV_PRMVIO_GRX ; 
 int /*<<< orphan*/  NV_PRMVIO_GX ; 

void
NVWriteVgaGr(struct drm_device *dev, int head, uint8_t index, uint8_t value)
{
	NVWritePRMVIO(dev, head, NV_PRMVIO_GRX, index);
	NVWritePRMVIO(dev, head, NV_PRMVIO_GX, value);
}