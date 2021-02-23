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
struct vlc_source {int /*<<< orphan*/  media_list_player; } ;

/* Variables and functions */
 int /*<<< orphan*/  libvlc_media_list_player_previous_ (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void vlcs_playlist_prev(void *data)
{
	struct vlc_source *c = data;

	libvlc_media_list_player_previous_(c->media_list_player);
}