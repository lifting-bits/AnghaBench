#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_msnd {int* left_levels; int* right_levels; int /*<<< orphan*/  mixer_lock; } ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_3__ {int* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;

/* Variables and functions */
 struct snd_msnd* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int snd_msndmix_volume_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_msnd *msnd = snd_kcontrol_chip(kcontrol);
	int addr = kcontrol->private_value;
	unsigned long flags;

	spin_lock_irqsave(&msnd->mixer_lock, flags);
	ucontrol->value.integer.value[0] = msnd->left_levels[addr] * 100;
	ucontrol->value.integer.value[0] /= 0xFFFF;
	ucontrol->value.integer.value[1] = msnd->right_levels[addr] * 100;
	ucontrol->value.integer.value[1] /= 0xFFFF;
	spin_unlock_irqrestore(&msnd->mixer_lock, flags);
	return 0;
}