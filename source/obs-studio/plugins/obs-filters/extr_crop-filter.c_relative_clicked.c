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
typedef  int /*<<< orphan*/  obs_property_t ;
typedef  int /*<<< orphan*/  obs_properties_t ;
typedef  int /*<<< orphan*/  obs_data_t ;

/* Variables and functions */
 int /*<<< orphan*/  UNUSED_PARAMETER (int /*<<< orphan*/ *) ; 
 int obs_data_get_bool (int /*<<< orphan*/ *,char*) ; 
 char* obs_module_text (char*) ; 
 int /*<<< orphan*/  obs_properties_get (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  obs_property_set_description (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  obs_property_set_visible (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static bool relative_clicked(obs_properties_t *props, obs_property_t *p,
			     obs_data_t *settings)
{
	bool relative = obs_data_get_bool(settings, "relative");

	obs_property_set_description(obs_properties_get(props, "left"),
				     relative ? obs_module_text("Crop.Left")
					      : "X");
	obs_property_set_description(obs_properties_get(props, "top"),
				     relative ? obs_module_text("Crop.Top")
					      : "Y");

	obs_property_set_visible(obs_properties_get(props, "right"), relative);
	obs_property_set_visible(obs_properties_get(props, "bottom"), relative);
	obs_property_set_visible(obs_properties_get(props, "cx"), !relative);
	obs_property_set_visible(obs_properties_get(props, "cy"), !relative);

	UNUSED_PARAMETER(p);
	return true;
}