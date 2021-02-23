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
typedef  int uint8 ;
typedef  int uint16 ;
typedef  int /*<<< orphan*/ * STREAM ;

/* Variables and functions */
 int ISO_PDU_DT ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  in_uint16_be (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  in_uint8 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  in_uint8s (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  next_be (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * tcp_recv (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static STREAM
iso_recv_msg(uint8 * code, uint8 * rdpver)
{
	STREAM s;
	uint16 length;
	uint8 version;

	s = tcp_recv(NULL, 4);
	if (s == NULL)
		return NULL;
	in_uint8(s, version);
	if (rdpver != NULL)
		*rdpver = version;
	if (version == 3)
	{
		in_uint8s(s, 1);	/* pad */
		in_uint16_be(s, length);
	}
	else
	{
		in_uint8(s, length);
		if (length & 0x80)
		{
			length &= ~0x80;
			next_be(s, length);
		}
	}
	if (length < 4)
	{
		error("Bad packet header\n");
		return NULL;
	}
	s = tcp_recv(s, length - 4);
	if (s == NULL)
		return NULL;
	if (version != 3)
		return s;
	in_uint8s(s, 1);	/* hdrlen */
	in_uint8(s, *code);
	if (*code == ISO_PDU_DT)
	{
		in_uint8s(s, 1);	/* eot */
		return s;
	}
	in_uint8s(s, 5);	/* dst_ref, src_ref, class */
	return s;
}