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
struct snd_ca_midi {scalar_t__ port; scalar_t__ dev_id; } ;
struct snd_ca0106 {int dummy; } ;

/* Variables and functions */
 scalar_t__ snd_ca0106_ptr_read (struct snd_ca0106*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned char ca0106_midi_read(struct snd_ca_midi *midi, int idx)
{
	return (unsigned char)snd_ca0106_ptr_read((struct snd_ca0106 *)(midi->dev_id),
						  midi->port + idx, 0);
}