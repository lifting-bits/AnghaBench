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
struct hda_codec {struct conexant_spec* spec; } ;
struct conexant_spec {int /*<<< orphan*/  parse_flags; } ;

/* Variables and functions */
#define  HDA_FIXUP_ACT_PRE_PROBE 128 
 int /*<<< orphan*/  HDA_PINCFG_HEADSET_MIC ; 

__attribute__((used)) static void cxt_fixup_headset_mic(struct hda_codec *codec,
				    const struct hda_fixup *fix, int action)
{
	struct conexant_spec *spec = codec->spec;

	switch (action) {
	case HDA_FIXUP_ACT_PRE_PROBE:
		spec->parse_flags |= HDA_PINCFG_HEADSET_MIC;
		break;
	}
}