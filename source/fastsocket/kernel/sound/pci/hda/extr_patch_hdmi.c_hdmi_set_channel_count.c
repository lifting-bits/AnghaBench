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
struct hda_codec {int dummy; } ;
typedef  int /*<<< orphan*/  hda_nid_t ;

/* Variables and functions */
 int /*<<< orphan*/  AC_VERB_SET_CVT_CHAN_COUNT ; 
 int hdmi_get_channel_count (struct hda_codec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_codec_write (struct hda_codec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void hdmi_set_channel_count(struct hda_codec *codec,
				   hda_nid_t cvt_nid, int chs)
{
	if (chs != hdmi_get_channel_count(codec, cvt_nid))
		snd_hda_codec_write(codec, cvt_nid, 0,
				    AC_VERB_SET_CVT_CHAN_COUNT, chs - 1);
}