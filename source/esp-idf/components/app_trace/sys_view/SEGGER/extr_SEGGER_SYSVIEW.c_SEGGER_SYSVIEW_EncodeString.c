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
 int /*<<< orphan*/ * _EncodeStr (int /*<<< orphan*/ *,char const*,unsigned int) ; 

U8* SEGGER_SYSVIEW_EncodeString(U8* pPayload, const char* s, unsigned int MaxLen) {
  return _EncodeStr(pPayload, s, MaxLen);
}