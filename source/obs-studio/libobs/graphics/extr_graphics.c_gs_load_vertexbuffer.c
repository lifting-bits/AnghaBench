#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  gs_vertbuffer_t ;
struct TYPE_4__ {int /*<<< orphan*/  (* device_load_vertexbuffer ) (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;
struct TYPE_5__ {int /*<<< orphan*/  device; TYPE_1__ exports; } ;
typedef  TYPE_2__ graphics_t ;

/* Variables and functions */
 int /*<<< orphan*/  gs_valid (char*) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_2__* thread_graphics ; 

void gs_load_vertexbuffer(gs_vertbuffer_t *vertbuffer)
{
	graphics_t *graphics = thread_graphics;

	if (!gs_valid("gs_load_vertexbuffer"))
		return;

	graphics->exports.device_load_vertexbuffer(graphics->device,
						   vertbuffer);
}