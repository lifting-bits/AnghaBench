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
typedef  int /*<<< orphan*/  libvlc_media_list_player_t ;

/* Variables and functions */
 int /*<<< orphan*/  lock (int /*<<< orphan*/ *) ; 
 int set_relative_playlist_position_and_play (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  unlock (int /*<<< orphan*/ *) ; 

int libvlc_media_list_player_next(libvlc_media_list_player_t * p_mlp)
{
    lock(p_mlp);
    int failure = set_relative_playlist_position_and_play(p_mlp, 1);
    unlock(p_mlp);
    return failure;
}