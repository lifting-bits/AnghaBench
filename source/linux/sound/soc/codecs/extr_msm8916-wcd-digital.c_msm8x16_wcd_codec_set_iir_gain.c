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
struct snd_soc_dapm_widget {int shift; int /*<<< orphan*/  dapm; } ;
struct snd_soc_component {int dummy; } ;
struct snd_kcontrol {int dummy; } ;

/* Variables and functions */
 int LPASS_CDC_IIR1_GAIN_B1_CTL ; 
 int LPASS_CDC_IIR2_GAIN_B1_CTL ; 
#define  SND_SOC_DAPM_POST_PMU 128 
 int snd_soc_component_read32 (struct snd_soc_component*,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int msm8x16_wcd_codec_set_iir_gain(struct snd_soc_dapm_widget *w,
		struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component =
			snd_soc_dapm_to_component(w->dapm);
	int value = 0, reg = 0;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		if (w->shift == 0)
			reg = LPASS_CDC_IIR1_GAIN_B1_CTL;
		else if (w->shift == 1)
			reg = LPASS_CDC_IIR2_GAIN_B1_CTL;
		value = snd_soc_component_read32(component, reg);
		snd_soc_component_write(component, reg, value);
		break;
	default:
		break;
	}
	return 0;
}