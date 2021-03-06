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
struct snd_soc_dapm_context {scalar_t__ component; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_soc_component_async_complete (scalar_t__) ; 

__attribute__((used)) static void soc_dapm_async_complete(struct snd_soc_dapm_context *dapm)
{
	if (dapm->component)
		snd_soc_component_async_complete(dapm->component);
}