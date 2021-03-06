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
struct ef4_channel {scalar_t__ rx_pkt_n_frags; } ;

/* Variables and functions */
 int /*<<< orphan*/  __ef4_rx_packet (struct ef4_channel*) ; 

__attribute__((used)) static inline void ef4_rx_flush_packet(struct ef4_channel *channel)
{
	if (channel->rx_pkt_n_frags)
		__ef4_rx_packet(channel);
}