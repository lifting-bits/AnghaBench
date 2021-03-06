#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/ * settings; } ;
struct TYPE_6__ {TYPE_1__ context; } ;
typedef  TYPE_2__ obs_source_t ;
typedef  int /*<<< orphan*/  obs_data_t ;

/* Variables and functions */
 int /*<<< orphan*/  obs_data_addref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  obs_source_valid (TYPE_2__ const*,char*) ; 

obs_data_t *obs_source_get_settings(const obs_source_t *source)
{
	if (!obs_source_valid(source, "obs_source_get_settings"))
		return NULL;

	obs_data_addref(source->context.settings);
	return source->context.settings;
}