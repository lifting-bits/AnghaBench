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
typedef  int /*<<< orphan*/  vout_thread_t ;
typedef  int /*<<< orphan*/  vlc_player_t ;

/* Variables and functions */
 size_t ARRAY_SIZE (char**) ; 
 char** osd_vars ; 
 int /*<<< orphan*/  var_DelCallback (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_player_VoutCallback ; 
 int /*<<< orphan*/  vlc_player_vout_OSDCallback ; 

void
vlc_player_vout_DelCallbacks(vlc_player_t *player, vout_thread_t *vout)
{
    var_DelCallback(vout, "fullscreen", vlc_player_VoutCallback, player);
    var_DelCallback(vout, "video-wallpaper", vlc_player_VoutCallback, player);

    for (size_t i = 0; i < ARRAY_SIZE(osd_vars); ++i)
        var_DelCallback(vout, osd_vars[i], vlc_player_vout_OSDCallback, player);
}