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
struct hda_fixup {int dummy; } ;
struct hda_codec {int dummy; } ;

/* Variables and functions */
 int HDA_FIXUP_ACT_INIT ; 
 int /*<<< orphan*/  alc882_gpio_mute (struct hda_codec*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void alc885_fixup_macpro_gpio(struct hda_codec *codec,
				     const struct hda_fixup *fix, int action)
{
	if (action != HDA_FIXUP_ACT_INIT)
		return;
	alc882_gpio_mute(codec, 0, 0);
	alc882_gpio_mute(codec, 1, 0);
}