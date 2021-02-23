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
typedef  int /*<<< orphan*/  u_int32_t ;
struct snd_mixer {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int ENXIO ; 
 int /*<<< orphan*/  KASSERT (int /*<<< orphan*/ ,char*) ; 
 int mixer_setrecsrc (struct snd_mixer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_mtxlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_mtxunlock (int /*<<< orphan*/ ) ; 

int
mix_setrecsrc(struct snd_mixer *m, u_int32_t src)
{
	int ret;

	KASSERT(m != NULL, ("NULL snd_mixer"));

	snd_mtxlock(m->lock);
	ret = mixer_setrecsrc(m, src);
	snd_mtxunlock(m->lock);

	return ((ret != 0) ? ENXIO : 0);
}