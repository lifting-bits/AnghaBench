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

/* Variables and functions */

__attribute__((used)) static void gfx_ctx_null_get_video_size(void *data, unsigned *width, unsigned *height)
{
   (void)data;
#ifdef VITA
   *width  = 960;
   *height = 544;
#else
   *width  = 320;
   *height = 240;
#endif
}