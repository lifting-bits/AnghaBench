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
struct snd_timer_instance {int flags; } ;

/* Variables and functions */
 int EINVAL ; 
 int SNDRV_TIMER_IFLG_SLAVE ; 
 int snd_timer_start1 (struct snd_timer_instance*,int,unsigned int) ; 
 int snd_timer_start_slave (struct snd_timer_instance*,int) ; 

int snd_timer_start(struct snd_timer_instance *timeri, unsigned int ticks)
{
	if (timeri == NULL || ticks < 1)
		return -EINVAL;
	if (timeri->flags & SNDRV_TIMER_IFLG_SLAVE)
		return snd_timer_start_slave(timeri, true);
	else
		return snd_timer_start1(timeri, true, ticks);
}