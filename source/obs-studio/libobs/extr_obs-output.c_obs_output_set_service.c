#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {TYPE_2__* output; scalar_t__ active; } ;
typedef  TYPE_1__ obs_service_t ;
struct TYPE_8__ {TYPE_1__* service; } ;
typedef  TYPE_2__ obs_output_t ;

/* Variables and functions */
 scalar_t__ active (TYPE_2__*) ; 
 int /*<<< orphan*/  obs_output_valid (TYPE_2__*,char*) ; 

void obs_output_set_service(obs_output_t *output, obs_service_t *service)
{
	if (!obs_output_valid(output, "obs_output_set_service"))
		return;
	if (active(output) || !service || service->active)
		return;

	if (service->output)
		service->output->service = NULL;

	output->service = service;
	service->output = output;
}