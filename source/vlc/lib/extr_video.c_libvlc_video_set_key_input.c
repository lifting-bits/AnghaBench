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
typedef  int /*<<< orphan*/  libvlc_media_player_t ;

/* Variables and functions */
 int /*<<< orphan*/  var_SetBool (int /*<<< orphan*/ *,char*,int) ; 

void libvlc_video_set_key_input( libvlc_media_player_t *p_mi, unsigned on )
{
    var_SetBool (p_mi, "keyboard-events", !!on);
}