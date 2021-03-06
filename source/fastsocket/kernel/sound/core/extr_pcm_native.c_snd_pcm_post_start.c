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
struct snd_pcm_substream {scalar_t__ stream; scalar_t__ timer; struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime2 {int hw_ptr_buffer_jiffies; } ;
struct snd_pcm_runtime {int buffer_size; int rate; scalar_t__ silence_size; int /*<<< orphan*/  trigger_tstamp; TYPE_1__* status; int /*<<< orphan*/  hw_ptr_jiffies; } ;
struct TYPE_2__ {int state; } ;

/* Variables and functions */
 int HZ ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
 int /*<<< orphan*/  SNDRV_TIMER_EVENT_MSTART ; 
 int /*<<< orphan*/  ULONG_MAX ; 
 int /*<<< orphan*/  jiffies ; 
 int /*<<< orphan*/  snd_pcm_playback_silence (struct snd_pcm_substream*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_trigger_tstamp (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_timer_notify (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void snd_pcm_post_start(struct snd_pcm_substream *substream, int state)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	snd_pcm_trigger_tstamp(substream);
	runtime->hw_ptr_jiffies = jiffies;
	((struct snd_pcm_runtime2 *)runtime)->hw_ptr_buffer_jiffies =
				(runtime->buffer_size * HZ) / runtime->rate;
	runtime->status->state = state;
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK &&
	    runtime->silence_size > 0)
		snd_pcm_playback_silence(substream, ULONG_MAX);
	if (substream->timer)
		snd_timer_notify(substream->timer, SNDRV_TIMER_EVENT_MSTART,
				 &runtime->trigger_tstamp);
}