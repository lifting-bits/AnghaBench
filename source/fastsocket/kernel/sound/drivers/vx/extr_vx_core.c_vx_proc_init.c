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
struct vx_core {int /*<<< orphan*/  card; } ;
struct snd_info_entry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_card_proc_new (int /*<<< orphan*/ ,char*,struct snd_info_entry**) ; 
 int /*<<< orphan*/  snd_info_set_text_ops (struct snd_info_entry*,struct vx_core*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vx_proc_read ; 

__attribute__((used)) static void vx_proc_init(struct vx_core *chip)
{
	struct snd_info_entry *entry;

	if (! snd_card_proc_new(chip->card, "vx-status", &entry))
		snd_info_set_text_ops(entry, chip, vx_proc_read);
}