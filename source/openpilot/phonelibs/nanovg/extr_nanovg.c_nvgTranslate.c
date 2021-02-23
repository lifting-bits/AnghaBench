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
struct TYPE_3__ {int /*<<< orphan*/  xform; } ;
typedef  TYPE_1__ NVGstate ;
typedef  int /*<<< orphan*/  NVGcontext ;

/* Variables and functions */
 int /*<<< orphan*/  nvgTransformPremultiply (int /*<<< orphan*/ ,float*) ; 
 int /*<<< orphan*/  nvgTransformTranslate (float*,float,float) ; 
 TYPE_1__* nvg__getState (int /*<<< orphan*/ *) ; 

void nvgTranslate(NVGcontext* ctx, float x, float y)
{
	NVGstate* state = nvg__getState(ctx);
	float t[6];
	nvgTransformTranslate(t, x,y);
	nvgTransformPremultiply(state->xform, t);
}