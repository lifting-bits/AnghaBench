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
typedef  int /*<<< orphan*/  uint32_t ;
struct obs_output_info {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 struct obs_output_info* find_output (char const*) ; 

uint32_t obs_get_output_flags(const char *id)
{
	const struct obs_output_info *info = find_output(id);
	return info ? info->flags : 0;
}