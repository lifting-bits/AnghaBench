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
struct TYPE_3__ {float x; float y; float w; float h; } ;
typedef  TYPE_1__ video_layout_bounds_t ;

/* Variables and functions */

video_layout_bounds_t make_bounds_unit(void)
{
   video_layout_bounds_t bounds;
   bounds.x = 0.0f;
   bounds.y = 0.0f;
   bounds.w = 1.0f;
   bounds.h = 1.0f;
   return bounds;
}