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
struct vlc_player_track {int /*<<< orphan*/  es_id; } ;
struct TYPE_3__ {int /*<<< orphan*/ * player; } ;
typedef  TYPE_1__ libvlc_media_player_t ;

/* Variables and functions */
 int /*<<< orphan*/  VLC_PLAYER_SELECT_EXCLUSIVE ; 
 int /*<<< orphan*/  libvlc_printerr (char*) ; 
 int vlc_es_id_GetInputId (int /*<<< orphan*/ ) ; 
 struct vlc_player_track* vlc_player_GetSubtitleTrackAt (int /*<<< orphan*/ *,size_t) ; 
 size_t vlc_player_GetSubtitleTrackCount (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_player_Lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_player_SelectTrack (int /*<<< orphan*/ *,struct vlc_player_track const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_player_Unlock (int /*<<< orphan*/ *) ; 

int libvlc_video_set_spu( libvlc_media_player_t *p_mi, int i_spu )
{
    int i_ret = -1;

    vlc_player_t *player = p_mi->player;
    vlc_player_Lock(player);

    size_t count = vlc_player_GetSubtitleTrackCount(player);
    for (size_t i = 0; i < count; i++)
    {
        const struct vlc_player_track *track =
            vlc_player_GetSubtitleTrackAt(player, i);
        if (i_spu == vlc_es_id_GetInputId(track->es_id))
        {
            /* found */
            vlc_player_SelectTrack(player, track, VLC_PLAYER_SELECT_EXCLUSIVE);
            i_ret = 0;
            goto end;
        }
    }
    libvlc_printerr( "Track identifier not found" );
end:
    vlc_player_Unlock(player);
    return i_ret;
}