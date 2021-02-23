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
typedef  int u16 ;
struct snd_soc_dai {struct snd_soc_codec* codec; } ;
struct snd_soc_codec {int dummy; } ;
struct snd_pcm_substream {scalar_t__ stream; struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int rate; } ;

/* Variables and functions */
 int AC97_EXTENDED_STATUS ; 
 int AC97_PCM_FRONT_DAC_RATE ; 
 int AC97_PCM_LR_ADC_RATE ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
 int ac97_read (struct snd_soc_codec*,int) ; 
 int ac97_write (struct snd_soc_codec*,int,int) ; 

__attribute__((used)) static int ac97_hifi_prepare(struct snd_pcm_substream *substream,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_codec *codec = dai->codec;
	struct snd_pcm_runtime *runtime = substream->runtime;
	int reg;
	u16 vra;

	vra = ac97_read(codec, AC97_EXTENDED_STATUS);
	ac97_write(codec, AC97_EXTENDED_STATUS, vra | 0x1);

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		reg = AC97_PCM_FRONT_DAC_RATE;
	else
		reg = AC97_PCM_LR_ADC_RATE;

	return ac97_write(codec, reg, runtime->rate);
}