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
struct drm_crtc_state {struct drm_crtc* crtc; } ;
struct drm_crtc {struct drm_crtc_state* state; } ;

/* Variables and functions */

void
__drm_atomic_helper_crtc_reset(struct drm_crtc *crtc,
			       struct drm_crtc_state *crtc_state)
{
	if (crtc_state)
		crtc_state->crtc = crtc;

	crtc->state = crtc_state;
}