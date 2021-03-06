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
struct user_element {int /*<<< orphan*/  elem_data_size; int /*<<< orphan*/  elem_data; } ;
struct snd_kcontrol {struct user_element* private_data; } ;
struct snd_ctl_elem_value {int /*<<< orphan*/  value; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_ctl_elem_user_get(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct user_element *ue = kcontrol->private_data;

	memcpy(&ucontrol->value, ue->elem_data, ue->elem_data_size);
	return 0;
}