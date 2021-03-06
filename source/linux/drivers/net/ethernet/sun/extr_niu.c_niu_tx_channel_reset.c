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
typedef  int /*<<< orphan*/  u64 ;
struct niu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TX_CS (int) ; 
 int /*<<< orphan*/  TX_CS_RST ; 
 int /*<<< orphan*/  TX_RING_KICK (int) ; 
 int niu_tx_cs_reset_poll (struct niu*,int) ; 
 int /*<<< orphan*/  nr64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nw64 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int niu_tx_channel_reset(struct niu *np, int channel)
{
	u64 val = nr64(TX_CS(channel));
	int err;

	val |= TX_CS_RST;
	nw64(TX_CS(channel), val);

	err = niu_tx_cs_reset_poll(np, channel);
	if (!err)
		nw64(TX_RING_KICK(channel), 0);

	return err;
}