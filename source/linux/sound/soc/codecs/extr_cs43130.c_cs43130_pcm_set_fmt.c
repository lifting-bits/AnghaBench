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
struct snd_soc_dai {size_t id; struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct cs43130_private {TYPE_1__* dais; } ;
struct TYPE_2__ {int dai_mode; int dai_format; } ;

/* Variables and functions */
 int EINVAL ; 
#define  SND_SOC_DAIFMT_CBM_CFM 133 
#define  SND_SOC_DAIFMT_CBS_CFS 132 
#define  SND_SOC_DAIFMT_DSP_A 131 
#define  SND_SOC_DAIFMT_DSP_B 130 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 129 
#define  SND_SOC_DAIFMT_LEFT_J 128 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,size_t,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 struct cs43130_private* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static int cs43130_pcm_set_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	struct cs43130_private *cs43130 = snd_soc_component_get_drvdata(component);

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBS_CFS:
		cs43130->dais[codec_dai->id].dai_mode = SND_SOC_DAIFMT_CBS_CFS;
		break;
	case SND_SOC_DAIFMT_CBM_CFM:
		cs43130->dais[codec_dai->id].dai_mode = SND_SOC_DAIFMT_CBM_CFM;
		break;
	default:
		dev_err(component->dev, "unsupported mode\n");
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		cs43130->dais[codec_dai->id].dai_format = SND_SOC_DAIFMT_I2S;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		cs43130->dais[codec_dai->id].dai_format = SND_SOC_DAIFMT_LEFT_J;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		cs43130->dais[codec_dai->id].dai_format = SND_SOC_DAIFMT_DSP_A;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		cs43130->dais[codec_dai->id].dai_format = SND_SOC_DAIFMT_DSP_B;
		break;
	default:
		dev_err(component->dev,
			"unsupported audio format\n");
		return -EINVAL;
	}

	dev_dbg(component->dev, "dai_id = %d,  dai_mode = %u, dai_format = %u\n",
		codec_dai->id,
		cs43130->dais[codec_dai->id].dai_mode,
		cs43130->dais[codec_dai->id].dai_format);

	return 0;
}