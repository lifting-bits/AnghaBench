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
typedef  int /*<<< orphan*/  u8 ;
struct dim_channel {scalar_t__ done_sw_buffers_number; scalar_t__ bytes_per_frame; scalar_t__ packet_length; int /*<<< orphan*/  addr; int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  state_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void channel_init(struct dim_channel *ch, u8 ch_addr)
{
	state_init(&ch->state);

	ch->addr = ch_addr;

	ch->packet_length = 0;
	ch->bytes_per_frame = 0;
	ch->done_sw_buffers_number = 0;
}