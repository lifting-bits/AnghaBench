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
typedef  int /*<<< orphan*/  obs_source_t ;

/* Variables and functions */
 int /*<<< orphan*/  obs_source_dosignal (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  obs_source_valid (int /*<<< orphan*/ *,char*) ; 

void obs_source_update_properties(obs_source_t *source)
{
	if (!obs_source_valid(source, "obs_source_update_properties"))
		return;

	obs_source_dosignal(source, NULL, "update_properties");
}