#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {float opacity; float stroke_opacity; int /*<<< orphan*/  stroke_color; int /*<<< orphan*/  transform; int /*<<< orphan*/  stroke; } ;
typedef  TYPE_1__ svg_state ;
typedef  int /*<<< orphan*/  svg_document ;
typedef  int /*<<< orphan*/  fz_path ;
typedef  int /*<<< orphan*/  fz_device ;
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */
 int /*<<< orphan*/  fz_default_color_params ; 
 int /*<<< orphan*/  fz_device_rgb (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fz_stroke_path (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,float,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void svg_stroke(fz_context *ctx, fz_device *dev, svg_document *doc, fz_path *path, svg_state *state)
{
	float opacity = state->opacity * state->stroke_opacity;
	if (path)
		fz_stroke_path(ctx, dev, path, &state->stroke, state->transform, fz_device_rgb(ctx), state->stroke_color, opacity, fz_default_color_params);
}