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
struct sun4i_rgb {int /*<<< orphan*/  panel; } ;
struct drm_connector {int dummy; } ;

/* Variables and functions */
 struct sun4i_rgb* drm_connector_to_sun4i_rgb (struct drm_connector*) ; 
 int drm_panel_get_modes (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int sun4i_rgb_get_modes(struct drm_connector *connector)
{
	struct sun4i_rgb *rgb =
		drm_connector_to_sun4i_rgb(connector);

	return drm_panel_get_modes(rgb->panel);
}