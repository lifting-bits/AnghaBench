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
typedef  enum es_format_category_e { ____Placeholder_es_format_category_e } es_format_category_e ;

/* Variables and functions */
#define  AUDIO_ES 129 
#define  SPU_ES 128 
 int /*<<< orphan*/  var_SetString (int /*<<< orphan*/ *,char*,char const*) ; 
 int /*<<< orphan*/  vlc_assert_unreachable () ; 
 int /*<<< orphan*/  vlc_player_assert_locked (int /*<<< orphan*/ *) ; 

void
vlc_player_SelectCategoryLanguage(vlc_player_t *player,
                                  enum es_format_category_e cat,
                                  const char *lang)
{
    vlc_player_assert_locked(player);
    switch (cat)
    {
        case AUDIO_ES:
            var_SetString(player, "audio-language", lang);
            break;
        case SPU_ES:
            var_SetString(player, "sub-language", lang);
            break;
        default:
            vlc_assert_unreachable();
    }
}