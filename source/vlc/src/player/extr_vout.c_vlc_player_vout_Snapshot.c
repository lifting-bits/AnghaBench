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
typedef  int /*<<< orphan*/  vlc_player_t ;

/* Variables and functions */
 int /*<<< orphan*/  vlc_player_vout_TriggerOption (int /*<<< orphan*/ *,char*) ; 

void
vlc_player_vout_Snapshot(vlc_player_t *player)
{
    vlc_player_vout_TriggerOption(player, "video-snapshot");
}