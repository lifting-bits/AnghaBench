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
struct priv {int prepause_samples; int /*<<< orphan*/  audio_fd; } ;
struct ao {int samplerate; struct priv* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  SNDCTL_DSP_RESET ; 
 int /*<<< orphan*/  close_device (struct ao*) ; 
 int get_delay (struct ao*) ; 
 int /*<<< orphan*/  ioctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void audio_pause(struct ao *ao)
{
    struct priv *p = ao->priv;
    p->prepause_samples = get_delay(ao) * ao->samplerate;
#if KEEP_DEVICE
    ioctl(p->audio_fd, SNDCTL_DSP_RESET, NULL);
#else
    close_device(ao);
#endif
}