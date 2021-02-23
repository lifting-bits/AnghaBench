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
struct TYPE_2__ {int is_paused; } ;
typedef  TYPE_1__ sdl_audio_t ;

/* Variables and functions */
 int /*<<< orphan*/  SDL_PauseAudio (int) ; 

__attribute__((used)) static bool sdl_audio_stop(void *data)
{
   sdl_audio_t *sdl = (sdl_audio_t*)data;
   sdl->is_paused = true;
   SDL_PauseAudio(1);
   return true;
}