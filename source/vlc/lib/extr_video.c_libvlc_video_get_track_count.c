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
typedef  int /*<<< orphan*/  vlc_player_t ;
struct TYPE_3__ {int /*<<< orphan*/ * player; } ;
typedef  TYPE_1__ libvlc_media_player_t ;

/* Variables and functions */
 int /*<<< orphan*/  VIDEO_ES ; 
 int vlc_player_GetTrackCount (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_player_Lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_player_Unlock (int /*<<< orphan*/ *) ; 

int libvlc_video_get_track_count( libvlc_media_player_t *p_mi )
{
    vlc_player_t *player = p_mi->player;
    vlc_player_Lock(player);

    int ret = vlc_player_GetTrackCount(p_mi->player, VIDEO_ES);

    vlc_player_Unlock(player);
    return ret;
}