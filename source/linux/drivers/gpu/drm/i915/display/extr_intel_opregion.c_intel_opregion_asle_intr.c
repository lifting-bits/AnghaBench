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
struct TYPE_2__ {int /*<<< orphan*/  asle_work; scalar_t__ asle; } ;
struct drm_i915_private {TYPE_1__ opregion; } ;

/* Variables and functions */
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 

void intel_opregion_asle_intr(struct drm_i915_private *dev_priv)
{
	if (dev_priv->opregion.asle)
		schedule_work(&dev_priv->opregion.asle_work);
}