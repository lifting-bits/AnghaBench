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
struct snd_soc_pcm_runtime {int /*<<< orphan*/  card; } ;
struct snd_pcm_substream {struct snd_soc_pcm_runtime* private_data; } ;
struct hdmi_audio_data {int dummy; } ;

/* Variables and functions */
 struct hdmi_audio_data* snd_soc_card_get_drvdata (int /*<<< orphan*/ ) ; 

__attribute__((used)) static
struct hdmi_audio_data *card_drvdata_substream(struct snd_pcm_substream *ss)
{
	struct snd_soc_pcm_runtime *rtd = ss->private_data;

	return snd_soc_card_get_drvdata(rtd->card);
}