#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
struct TYPE_4__ {int /*<<< orphan*/  (* Write ) (TYPE_1__*,int /*<<< orphan*/ *) ;} ;
typedef  TYPE_1__ CONSOLE ;

/* Variables and functions */
 scalar_t__ UniIsEmptyStr (int /*<<< orphan*/ *) ; 
 scalar_t__ UniStrCmpi (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ UniStrToIP32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * _UU (char*) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int /*<<< orphan*/ *) ; 

bool CmdEvalIp(CONSOLE *c, wchar_t *str, void *param)
{
	// Validate arguments
	if (c == NULL || str == NULL)
	{
		return false;
	}

	if (UniIsEmptyStr(str))
	{
		return true;
	}

	if (UniStrToIP32(str) == 0 && UniStrCmpi(str, L"0.0.0.0") != 0)
	{
		wchar_t *msg = (param == NULL) ? _UU("CMD_IP_EVAL_FAILED") : (wchar_t *)param;
		c->Write(c, msg);
		return false;
	}

	return true;
}