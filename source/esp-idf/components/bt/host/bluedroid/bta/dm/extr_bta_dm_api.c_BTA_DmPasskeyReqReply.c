#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  event; } ;
struct TYPE_5__ {int /*<<< orphan*/  passkey; int /*<<< orphan*/  accept; int /*<<< orphan*/  bd_addr; TYPE_1__ hdr; } ;
typedef  TYPE_2__ tBTA_DM_API_KEY_REQ ;
typedef  int /*<<< orphan*/  UINT32 ;
typedef  int /*<<< orphan*/  BOOLEAN ;
typedef  int /*<<< orphan*/  BD_ADDR ;

/* Variables and functions */
 int /*<<< orphan*/  BTA_DM_API_KEY_REQ_EVT ; 
 int /*<<< orphan*/  bdcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bta_sys_sendmsg (TYPE_2__*) ; 
 scalar_t__ osi_malloc (int) ; 

void BTA_DmPasskeyReqReply(BOOLEAN accept, BD_ADDR bd_addr, UINT32 passkey)
{
    tBTA_DM_API_KEY_REQ    *p_msg;
    if ((p_msg = (tBTA_DM_API_KEY_REQ *) osi_malloc(sizeof(tBTA_DM_API_KEY_REQ))) != NULL) {
        p_msg->hdr.event = BTA_DM_API_KEY_REQ_EVT;
        bdcpy(p_msg->bd_addr, bd_addr);
        p_msg->accept = accept;
        p_msg->passkey = passkey;
        bta_sys_sendmsg(p_msg);
    }
}