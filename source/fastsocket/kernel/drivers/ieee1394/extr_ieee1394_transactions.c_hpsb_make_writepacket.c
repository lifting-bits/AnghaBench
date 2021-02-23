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
struct hpsb_packet {scalar_t__* data; int /*<<< orphan*/  node_id; struct hpsb_host* host; } ;
struct hpsb_host {int dummy; } ;
typedef  int /*<<< orphan*/  quadlet_t ;
typedef  int /*<<< orphan*/  nodeid_t ;

/* Variables and functions */
 int /*<<< orphan*/  fill_async_writeblock (struct hpsb_packet*,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  fill_async_writequad (struct hpsb_packet*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct hpsb_packet* hpsb_alloc_packet (size_t) ; 
 int /*<<< orphan*/  hpsb_free_packet (struct hpsb_packet*) ; 
 scalar_t__ hpsb_get_tlabel (struct hpsb_packet*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,int /*<<< orphan*/ *,size_t) ; 

struct hpsb_packet *hpsb_make_writepacket(struct hpsb_host *host, nodeid_t node,
					  u64 addr, quadlet_t * buffer,
					  size_t length)
{
	struct hpsb_packet *packet;

	if (length == 0)
		return NULL;

	packet = hpsb_alloc_packet(length);
	if (!packet)
		return NULL;

	if (length % 4) {	/* zero padding bytes */
		packet->data[length >> 2] = 0;
	}
	packet->host = host;
	packet->node_id = node;

	if (hpsb_get_tlabel(packet)) {
		hpsb_free_packet(packet);
		return NULL;
	}

	if (length == 4) {
		fill_async_writequad(packet, addr, buffer ? *buffer : 0);
	} else {
		fill_async_writeblock(packet, addr, length);
		if (buffer)
			memcpy(packet->data, buffer, length);
	}

	return packet;
}