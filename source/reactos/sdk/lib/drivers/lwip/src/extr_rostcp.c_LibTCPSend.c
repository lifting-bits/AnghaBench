#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32_t ;
typedef  int /*<<< orphan*/  u16_t ;
struct TYPE_7__ {scalar_t__ Error; int /*<<< orphan*/  Information; } ;
struct TYPE_8__ {TYPE_3__ Send; } ;
struct TYPE_5__ {void* Data; int /*<<< orphan*/  DataLength; int /*<<< orphan*/  Connection; } ;
struct TYPE_6__ {TYPE_1__ Send; } ;
struct lwip_callback_msg {TYPE_4__ Output; int /*<<< orphan*/  Event; TYPE_2__ Input; } ;
typedef  scalar_t__ err_t ;
typedef  int /*<<< orphan*/  PCONNECTION_ENDPOINT ;

/* Variables and functions */
 scalar_t__ ERR_CLSD ; 
 scalar_t__ ERR_MEM ; 
 scalar_t__ ERR_OK ; 
 struct lwip_callback_msg* ExAllocateFromNPagedLookasideList (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ExFreeToNPagedLookasideList (int /*<<< orphan*/ *,struct lwip_callback_msg*) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  KeInitializeEvent (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LibTCPSendCallback (struct lwip_callback_msg*) ; 
 int /*<<< orphan*/  MessageLookasideList ; 
 int /*<<< orphan*/  NotificationEvent ; 
 scalar_t__ WaitForEventSafely (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tcpip_callback_with_block (int /*<<< orphan*/  (*) (struct lwip_callback_msg*),struct lwip_callback_msg*,int) ; 

err_t
LibTCPSend(PCONNECTION_ENDPOINT Connection, void *const dataptr, const u16_t len, u32_t *sent, const int safe)
{
    err_t ret;
    struct lwip_callback_msg *msg;

    msg = ExAllocateFromNPagedLookasideList(&MessageLookasideList);
    if (msg)
    {
        KeInitializeEvent(&msg->Event, NotificationEvent, FALSE);
        msg->Input.Send.Connection = Connection;
        msg->Input.Send.Data = dataptr;
        msg->Input.Send.DataLength = len;

        if (safe)
            LibTCPSendCallback(msg);
        else
            tcpip_callback_with_block(LibTCPSendCallback, msg, 1);

        if (WaitForEventSafely(&msg->Event))
            ret = msg->Output.Send.Error;
        else
            ret = ERR_CLSD;

        if (ret == ERR_OK)
            *sent = msg->Output.Send.Information;
        else
            *sent = 0;

        ExFreeToNPagedLookasideList(&MessageLookasideList, msg);

        return ret;
    }

    return ERR_MEM;
}