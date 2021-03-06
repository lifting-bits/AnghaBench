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
typedef  void* uint32_t ;
struct zwlr_layer_surface_v1 {int dummy; } ;
struct swaybar_output {void* height; void* width; } ;

/* Variables and functions */
 int /*<<< orphan*/  set_output_dirty (struct swaybar_output*) ; 
 int /*<<< orphan*/  zwlr_layer_surface_v1_ack_configure (struct zwlr_layer_surface_v1*,void*) ; 

__attribute__((used)) static void layer_surface_configure(void *data,
		struct zwlr_layer_surface_v1 *surface,
		uint32_t serial, uint32_t width, uint32_t height) {
	struct swaybar_output *output = data;
	output->width = width;
	output->height = height;
	zwlr_layer_surface_v1_ack_configure(surface, serial);
	set_output_dirty(output);
}