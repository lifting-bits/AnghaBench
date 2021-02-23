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
 int /*<<< orphan*/  PLAY_SONG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UC_LNX ; 
 int /*<<< orphan*/  _delay_ms (int) ; 
 int /*<<< orphan*/  set_unicode_input_mode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tone_startup ; 

void startup_user() {
  _delay_ms(20); // gets rid of tick
  set_unicode_input_mode(UC_LNX);
#ifdef AUDIO_ENABLE
  PLAY_SONG(tone_startup);
#endif
}