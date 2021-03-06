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
struct obs_encoder_info {int dummy; } ;
typedef  int /*<<< orphan*/  obs_data_t ;

/* Variables and functions */
 struct obs_encoder_info* find_encoder (char const*) ; 
 int /*<<< orphan*/ * get_defaults (struct obs_encoder_info const*) ; 

obs_data_t *obs_encoder_defaults(const char *id)
{
	const struct obs_encoder_info *info = find_encoder(id);
	return (info) ? get_defaults(info) : NULL;
}