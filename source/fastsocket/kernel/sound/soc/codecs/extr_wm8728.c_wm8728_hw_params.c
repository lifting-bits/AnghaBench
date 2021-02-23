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
typedef  int u16 ;
struct snd_soc_pcm_runtime {struct snd_soc_device* socdev; } ;
struct snd_soc_device {TYPE_1__* card; } ;
struct snd_soc_dai {int dummy; } ;
struct snd_soc_codec {int dummy; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct TYPE_2__ {struct snd_soc_codec* codec; } ;

/* Variables and functions */
 int EINVAL ; 
#define  SNDRV_PCM_FORMAT_S16_LE 130 
#define  SNDRV_PCM_FORMAT_S20_3LE 129 
#define  SNDRV_PCM_FORMAT_S24_LE 128 
 int /*<<< orphan*/  WM8728_DACCTL ; 
 int params_format (struct snd_pcm_hw_params*) ; 
 int snd_soc_read (struct snd_soc_codec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_write (struct snd_soc_codec*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int wm8728_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params,
	struct snd_soc_dai *dai)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_device *socdev = rtd->socdev;
	struct snd_soc_codec *codec = socdev->card->codec;
	u16 dac = snd_soc_read(codec, WM8728_DACCTL);

	dac &= ~0x18;

	switch (params_format(params)) {
	case SNDRV_PCM_FORMAT_S16_LE:
		break;
	case SNDRV_PCM_FORMAT_S20_3LE:
		dac |= 0x10;
		break;
	case SNDRV_PCM_FORMAT_S24_LE:
		dac |= 0x08;
		break;
	default:
		return -EINVAL;
	}

	snd_soc_write(codec, WM8728_DACCTL, dac);

	return 0;
}