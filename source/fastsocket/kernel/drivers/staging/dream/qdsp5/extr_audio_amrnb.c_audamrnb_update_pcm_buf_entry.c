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
typedef  int uint8_t ;
typedef  int uint32_t ;
struct audio {size_t fill_next; scalar_t__ pcm_buf_count; int buf_refresh; int /*<<< orphan*/  read_wait; int /*<<< orphan*/  dsp_lock; TYPE_1__* in; } ;
struct TYPE_2__ {int addr; int used; } ;

/* Variables and functions */
 int /*<<< orphan*/  audamrnb_buffer_refresh (struct audio*) ; 
 int /*<<< orphan*/  dprintk (char*,...) ; 
 int /*<<< orphan*/  pr_err (char*,int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void audamrnb_update_pcm_buf_entry(struct audio *audio,
		uint32_t *payload)
{
	uint8_t index;
	unsigned long flags;

	spin_lock_irqsave(&audio->dsp_lock, flags);
	for (index = 0; index < payload[1]; index++) {
		if (audio->in[audio->fill_next].addr ==
		    payload[2 + index * 2]) {
			dprintk("audamrnb_update_pcm_buf_entry: in[%d] ready\n",
				audio->fill_next);
			audio->in[audio->fill_next].used =
			    payload[3 + index * 2];
			if ((++audio->fill_next) == audio->pcm_buf_count)
				audio->fill_next = 0;

		} else {
			pr_err
			  ("audamrnb_update_pcm_buf_entry: expected=%x ret=%x\n"
			   , audio->in[audio->fill_next].addr,
			   payload[1 + index * 2]);
			break;
		}
	}
	if (audio->in[audio->fill_next].used == 0) {
		audamrnb_buffer_refresh(audio);
	} else {
		dprintk("audamrnb_update_pcm_buf_entry: read cannot keep up\n");
		audio->buf_refresh = 1;
	}

	spin_unlock_irqrestore(&audio->dsp_lock, flags);
	wake_up(&audio->read_wait);
}