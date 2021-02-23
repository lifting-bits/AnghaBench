#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {scalar_t__ playing; } ;
struct TYPE_6__ {int play_mode; TYPE_1__ flags; scalar_t__ write_buffer_size; int /*<<< orphan*/ * write_buffer; int /*<<< orphan*/  play_codec; int /*<<< orphan*/  board; } ;
typedef  TYPE_2__ IXJ ;

/* Variables and functions */
 int /*<<< orphan*/  ixj_WriteDSPCommand (int,TYPE_2__*) ; 
 int ixjdebug ; 
 int /*<<< orphan*/  jiffies ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ixj_play_stop(IXJ *j)
{
	if (ixjdebug & 0x0002)
		printk("IXJ %d Stopping Play Codec %d at %ld\n", j->board, j->play_codec, jiffies);

	kfree(j->write_buffer);
	j->write_buffer = NULL;
	j->write_buffer_size = 0;
	if (j->play_mode > -1) {
		ixj_WriteDSPCommand(0x5221, j);	/* Stop playback and flush buffers.  8022 reference page 9-40 */

		j->play_mode = -1;
	}
	j->flags.playing = 0;
}