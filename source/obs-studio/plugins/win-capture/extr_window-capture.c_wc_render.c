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
struct window_capture {int /*<<< orphan*/  capture; } ;
typedef  int /*<<< orphan*/  gs_effect_t ;

/* Variables and functions */
 int /*<<< orphan*/  OBS_EFFECT_OPAQUE ; 
 int /*<<< orphan*/  UNUSED_PARAMETER (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dc_capture_render (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  obs_get_base_effect (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void wc_render(void *data, gs_effect_t *effect)
{
	struct window_capture *wc = data;
	dc_capture_render(&wc->capture, obs_get_base_effect(OBS_EFFECT_OPAQUE));

	UNUSED_PARAMETER(effect);
}