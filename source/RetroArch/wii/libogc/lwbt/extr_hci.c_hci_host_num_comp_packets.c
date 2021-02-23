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
typedef  int u8_t ;
typedef  scalar_t__ u16_t ;
struct pbuf {int /*<<< orphan*/  tot_len; scalar_t__ payload; } ;
typedef  int /*<<< orphan*/  err_t ;
struct TYPE_2__ {int /*<<< orphan*/  host_num_acl; } ;

/* Variables and functions */
 int /*<<< orphan*/  ERROR (char*) ; 
 int /*<<< orphan*/  ERR_MEM ; 
 int /*<<< orphan*/  ERR_OK ; 
 int /*<<< orphan*/  HCI_HC_BB_OGF ; 
 int /*<<< orphan*/  HCI_H_NUM_COMPL_OCF ; 
 int /*<<< orphan*/  HCI_H_NUM_COMPL_PLEN ; 
 int /*<<< orphan*/  PBUF_RAM ; 
 int /*<<< orphan*/  PBUF_RAW ; 
 struct pbuf* btpbuf_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  btpbuf_free (struct pbuf*) ; 
 struct pbuf* hci_cmd_ass (struct pbuf*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__* hci_dev ; 
 scalar_t__ htole16 (scalar_t__) ; 
 int /*<<< orphan*/  physbusif_output (struct pbuf*,int /*<<< orphan*/ ) ; 

err_t hci_host_num_comp_packets(u16_t conhdl, u16_t num_complete)
{
	struct pbuf *p;

	if((p = btpbuf_alloc(PBUF_RAW, HCI_H_NUM_COMPL_PLEN, PBUF_RAM)) == NULL) {
		ERROR("hci_host_num_comp_packets: Could not allocate memory for pbuf\n");
		return ERR_MEM;
	}
	/* Assembling command packet */
	p = hci_cmd_ass(p, HCI_H_NUM_COMPL_OCF, HCI_HC_BB_OGF, HCI_H_NUM_COMPL_PLEN);
	((u8_t*)p->payload)[4] = 1;
	*(u16_t*)(p->payload+5) = htole16(conhdl);
	*(u16_t*)(p->payload+7) = htole16(num_complete); /* Number of completed acl packets */

	physbusif_output(p, p->tot_len);
	btpbuf_free(p);

	hci_dev->host_num_acl += num_complete;

	return ERR_OK;
}