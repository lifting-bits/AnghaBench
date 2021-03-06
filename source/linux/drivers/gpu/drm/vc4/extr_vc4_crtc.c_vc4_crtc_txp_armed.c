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
struct vc4_crtc_state {int txp_armed; } ;
struct drm_crtc_state {int dummy; } ;

/* Variables and functions */
 struct vc4_crtc_state* to_vc4_crtc_state (struct drm_crtc_state*) ; 

void vc4_crtc_txp_armed(struct drm_crtc_state *state)
{
	struct vc4_crtc_state *vc4_state = to_vc4_crtc_state(state);

	vc4_state->txp_armed = true;
}