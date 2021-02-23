#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  window; } ;
typedef  TYPE_1__ sdl2_video_t ;

/* Variables and functions */
 int /*<<< orphan*/  SDL_GetWindowGrab (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_SetWindowGrab (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sdl2_grab_mouse_toggle(void *data)
{
   sdl2_video_t *vid = (sdl2_video_t*)data;
   SDL_SetWindowGrab(vid->window, SDL_GetWindowGrab(vid->window));
}