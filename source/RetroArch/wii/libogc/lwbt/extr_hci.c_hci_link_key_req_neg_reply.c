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
typedef  int /*<<< orphan*/  u8_t ;
struct pbuf {int /*<<< orphan*/  tot_len; scalar_t__ payload; } ;
struct bd_addr {int /*<<< orphan*/  addr; } ;
typedef  int /*<<< orphan*/  err_t ;

/* Variables and functions */
 int /*<<< orphan*/  ERROR (char*) ; 
 int /*<<< orphan*/  ERR_MEM ; 
 int /*<<< orphan*/  ERR_OK ; 
 int /*<<< orphan*/  HCI_LINK_CTRL_OGF ; 
 int /*<<< orphan*/  HCI_LINK_KEY_REQ_REP_NEG ; 
 int /*<<< orphan*/  HCI_LINK_KEY_REQ_REP_NEG_PLEN ; 
 int /*<<< orphan*/  PBUF_RAM ; 
 int /*<<< orphan*/  PBUF_RAW ; 
 struct pbuf* btpbuf_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  btpbuf_free (struct pbuf*) ; 
 struct pbuf* hci_cmd_ass (struct pbuf*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  physbusif_output (struct pbuf*,int /*<<< orphan*/ ) ; 

err_t hci_link_key_req_neg_reply(struct bd_addr *bdaddr)
{
        struct pbuf *p;

        if ((p = btpbuf_alloc(PBUF_RAW, HCI_LINK_KEY_REQ_REP_NEG_PLEN, PBUF_RAM)) == NULL) {
                ERROR("hci_link_key_req_neg_repl: Could not allocate memory for pbuf\n");
                return ERR_MEM;
        }

        p = hci_cmd_ass(p, HCI_LINK_KEY_REQ_REP_NEG, HCI_LINK_CTRL_OGF, HCI_LINK_KEY_REQ_REP_NEG_PLEN);
        memcpy(((u8_t *)p->payload)+4, bdaddr->addr, 6);

        physbusif_output(p,p->tot_len);
        btpbuf_free(p);

        return ERR_OK;
}