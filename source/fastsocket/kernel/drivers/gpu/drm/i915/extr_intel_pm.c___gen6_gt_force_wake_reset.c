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
struct drm_i915_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ECOBUS ; 
 int /*<<< orphan*/  FORCEWAKE ; 
 int /*<<< orphan*/  I915_WRITE_NOTRACE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  POSTING_READ (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void __gen6_gt_force_wake_reset(struct drm_i915_private *dev_priv)
{
	I915_WRITE_NOTRACE(FORCEWAKE, 0);
	POSTING_READ(ECOBUS); /* something from same cacheline, but !FORCEWAKE */
}