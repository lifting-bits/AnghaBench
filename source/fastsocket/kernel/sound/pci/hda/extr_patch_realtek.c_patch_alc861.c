#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct hda_codec {int /*<<< orphan*/  patch_ops; struct alc_spec* spec; } ;
struct TYPE_2__ {int beep_nid; int /*<<< orphan*/  no_analog; } ;
struct alc_spec {int /*<<< orphan*/  power_hook; TYPE_1__ gen; } ;

/* Variables and functions */
 int /*<<< orphan*/  HDA_FIXUP_ACT_PRE_PROBE ; 
 int /*<<< orphan*/  HDA_FIXUP_ACT_PROBE ; 
 int /*<<< orphan*/  HDA_OUTPUT ; 
 int /*<<< orphan*/  alc861_fixup_tbl ; 
 int /*<<< orphan*/  alc861_fixups ; 
 int alc861_parse_auto_config (struct hda_codec*) ; 
 int alc_alloc_spec (struct hda_codec*,int) ; 
 int /*<<< orphan*/  alc_free (struct hda_codec*) ; 
 int /*<<< orphan*/  alc_patch_ops ; 
 int /*<<< orphan*/  alc_power_eapd ; 
 int /*<<< orphan*/  set_beep_amp (struct alc_spec*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_apply_fixup (struct hda_codec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_pick_fixup (struct hda_codec*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int patch_alc861(struct hda_codec *codec)
{
	struct alc_spec *spec;
	int err;

	err = alc_alloc_spec(codec, 0x15);
	if (err < 0)
		return err;

	spec = codec->spec;
	spec->gen.beep_nid = 0x23;

	snd_hda_pick_fixup(codec, NULL, alc861_fixup_tbl, alc861_fixups);
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);

	/* automatic parse from the BIOS config */
	err = alc861_parse_auto_config(codec);
	if (err < 0)
		goto error;

	if (!spec->gen.no_analog)
		set_beep_amp(spec, 0x23, 0, HDA_OUTPUT);

	codec->patch_ops = alc_patch_ops;
#ifdef CONFIG_PM
	spec->power_hook = alc_power_eapd;
#endif

	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);

	return 0;

 error:
	alc_free(codec);
	return err;
}