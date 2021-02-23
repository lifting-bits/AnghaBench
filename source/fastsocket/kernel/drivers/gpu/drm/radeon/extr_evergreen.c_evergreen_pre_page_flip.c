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
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  radeon_irq_kms_pflip_irq_get (struct radeon_device*,int) ; 

void evergreen_pre_page_flip(struct radeon_device *rdev, int crtc)
{
	/* enable the pflip int */
	radeon_irq_kms_pflip_irq_get(rdev, crtc);
}