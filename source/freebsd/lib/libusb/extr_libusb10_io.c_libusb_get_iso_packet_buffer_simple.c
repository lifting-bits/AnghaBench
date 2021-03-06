#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
struct libusb_transfer {scalar_t__ num_iso_packets; TYPE_1__* iso_packet_desc; int /*<<< orphan*/ * buffer; } ;
struct TYPE_2__ {int length; } ;

/* Variables and functions */

uint8_t *
libusb_get_iso_packet_buffer_simple(struct libusb_transfer *transfer, uint32_t off)
{
	uint8_t *ptr;

	if (transfer->num_iso_packets < 0)
		return (NULL);

	if (off >= (uint32_t)transfer->num_iso_packets)
		return (NULL);

	ptr = transfer->buffer;
	if (ptr == NULL)
		return (NULL);

	ptr += transfer->iso_packet_desc[0].length * off;

	return (ptr);
}