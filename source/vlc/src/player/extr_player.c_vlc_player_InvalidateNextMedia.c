#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int next_media_requested; int /*<<< orphan*/ * next_media; } ;
typedef  TYPE_1__ vlc_player_t ;

/* Variables and functions */
 int /*<<< orphan*/  input_item_Release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_player_assert_locked (TYPE_1__*) ; 

void
vlc_player_InvalidateNextMedia(vlc_player_t *player)
{
    vlc_player_assert_locked(player);
    if (player->next_media)
    {
        input_item_Release(player->next_media);
        player->next_media = NULL;
    }
    player->next_media_requested = false;

}