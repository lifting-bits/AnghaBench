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
typedef  int /*<<< orphan*/  U8 ;

/* Variables and functions */
 int /*<<< orphan*/  RECORD_END () ; 
 int /*<<< orphan*/  RECORD_START (scalar_t__) ; 
 scalar_t__ SEGGER_SYSVIEW_INFO_SIZE ; 
 scalar_t__ SEGGER_SYSVIEW_MAX_STRING_LEN ; 
 int /*<<< orphan*/  SYSVIEW_EVTID_SYSDESC ; 
 int /*<<< orphan*/ * _EncodeStr (int /*<<< orphan*/ *,char const*,scalar_t__) ; 
 int /*<<< orphan*/  _SendPacket (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void SEGGER_SYSVIEW_SendSysDesc(const char *sSysDesc) {
  U8* pPayload;
  U8* pPayloadStart;
  RECORD_START(SEGGER_SYSVIEW_INFO_SIZE + 1 + SEGGER_SYSVIEW_MAX_STRING_LEN);
  //
  pPayload = _EncodeStr(pPayloadStart, sSysDesc, SEGGER_SYSVIEW_MAX_STRING_LEN);
  _SendPacket(pPayloadStart, pPayload, SYSVIEW_EVTID_SYSDESC);
  RECORD_END();
}