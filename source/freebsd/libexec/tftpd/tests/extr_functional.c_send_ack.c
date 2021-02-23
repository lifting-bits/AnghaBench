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
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  packet ;

/* Variables and functions */
 int /*<<< orphan*/  send_bytes (char*,int) ; 

__attribute__((used)) static void
send_ack(uint16_t blocknum)
{
	char packet[] = {
	    0, 4,	/* ACK opcode in BE */
	    blocknum >> 8,
	    blocknum & 0xFF
	};

	send_bytes(packet, sizeof(packet));

}