#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8 ;
typedef  int uint16 ;
struct TYPE_9__ {int end; int p; } ;
typedef  TYPE_1__* STREAM ;

/* Variables and functions */
 int RDP_PDU_DATA ; 
 int /*<<< orphan*/  SEC_ENCRYPT ; 
 scalar_t__ g_encryption ; 
 int g_mcs_userid ; 
 int /*<<< orphan*/  g_rdp_shareid ; 
 int /*<<< orphan*/  out_uint16 (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_uint16_le (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint32_le (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_uint8 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  rdp_hdr ; 
 int /*<<< orphan*/  s_pop_layer (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sec_send (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
rdp_send_data(STREAM s, uint8 data_pdu_type)
{
	uint16 length;

	s_pop_layer(s, rdp_hdr);
	length = s->end - s->p;

	out_uint16_le(s, length);
	out_uint16_le(s, (RDP_PDU_DATA | 0x10));
	out_uint16_le(s, (g_mcs_userid + 1001));

	out_uint32_le(s, g_rdp_shareid);
	out_uint8(s, 0);	/* pad */
	out_uint8(s, 1);	/* streamid */
	out_uint16_le(s, (length - 14));
	out_uint8(s, data_pdu_type);
	out_uint8(s, 0);	/* compress_type */
	out_uint16(s, 0);	/* compress_len */

	sec_send(s, g_encryption ? SEC_ENCRYPT : 0);
}