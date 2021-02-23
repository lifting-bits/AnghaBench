#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  tmp4 ;
typedef  int /*<<< orphan*/  tmp2 ;
typedef  int /*<<< orphan*/  tmp ;
typedef  int /*<<< orphan*/  t ;
typedef  scalar_t__ UINT ;
struct TYPE_17__ {scalar_t__ Priority; scalar_t__ UniqueId; scalar_t__ Id; int /*<<< orphan*/  Note; scalar_t__ Active; scalar_t__ Discard; } ;
struct TYPE_16__ {int /*<<< orphan*/  (* Write ) (TYPE_3__*,int /*<<< orphan*/ ) ;} ;
struct TYPE_15__ {int /*<<< orphan*/  Rpc; int /*<<< orphan*/ * HubName; } ;
struct TYPE_14__ {scalar_t__ NumAccess; TYPE_4__* Accesses; int /*<<< orphan*/  HubName; } ;
typedef  TYPE_1__ RPC_ENUM_ACCESS_LIST ;
typedef  TYPE_2__ PS ;
typedef  int /*<<< orphan*/  LIST ;
typedef  int /*<<< orphan*/  CT ;
typedef  TYPE_3__ CONSOLE ;
typedef  TYPE_4__ ACCESS ;

/* Variables and functions */
 int /*<<< orphan*/  CmdPrintError (TYPE_3__*,scalar_t__) ; 
 int /*<<< orphan*/  CtFreeEx (int /*<<< orphan*/ *,TYPE_3__*,int) ; 
 int /*<<< orphan*/  CtInsert (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CtInsertColumn (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * CtNew () ; 
 scalar_t__ ERR_INVALID_PARAMETER ; 
 scalar_t__ ERR_NO_ERROR ; 
 int /*<<< orphan*/  FreeParamValueList (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FreeRpcEnumAccessList (TYPE_1__*) ; 
 int /*<<< orphan*/  GetAccessListStr (char*,int,TYPE_4__*) ; 
 int MAX_SIZE ; 
 int /*<<< orphan*/ * ParseCommandList (TYPE_3__*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ ScEnumAccess (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  StrCpy (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  StrToUni (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  UniStrCpy (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UniToStru (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  Zero (TYPE_1__*,int) ; 
 int /*<<< orphan*/  _UU (char*) ; 
 int /*<<< orphan*/  stub1 (TYPE_3__*,int /*<<< orphan*/ ) ; 

UINT PsAccessList(CONSOLE *c, char *cmd_name, wchar_t *str, void *param)
{
	LIST *o;
	PS *ps = (PS *)param;
	UINT ret = 0;
	RPC_ENUM_ACCESS_LIST t;
	CT *ct;
	UINT i;
	
	// If virtual HUB is not selected, it's an error
	if (ps->HubName == NULL)
	{
		c->Write(c, _UU("CMD_Hub_Not_Selected"));
		return ERR_INVALID_PARAMETER;
	}

	o = ParseCommandList(c, cmd_name, str, NULL, 0);
	if (o == NULL)
	{
		return ERR_INVALID_PARAMETER;
	}

	Zero(&t, sizeof(t));
	StrCpy(t.HubName, sizeof(t.HubName), ps->HubName);

	// RPC call
	ret = ScEnumAccess(ps->Rpc, &t);

	if (ret != ERR_NO_ERROR)
	{
		// An error has occured
		CmdPrintError(c, ret);
		FreeParamValueList(o);
		return ret;
	}

	ct = CtNew();
	CtInsertColumn(ct, _UU("SM_ACCESS_COLUMN_0"), true);
	CtInsertColumn(ct, _UU("SM_ACCESS_COLUMN_1"), true);
	CtInsertColumn(ct, _UU("SM_ACCESS_COLUMN_2"), true);
	CtInsertColumn(ct, _UU("SM_ACCESS_COLUMN_3"), true);
	CtInsertColumn(ct, _UU("SM_ACCESS_COLUMN_6"), true);
	CtInsertColumn(ct, _UU("SM_ACCESS_COLUMN_5"), false);
	CtInsertColumn(ct, _UU("SM_ACCESS_COLUMN_4"), false);

	for (i = 0;i < t.NumAccess;i++)
	{
		ACCESS *a = &t.Accesses[i];
		char tmp[MAX_SIZE];
		wchar_t tmp3[MAX_SIZE];
		wchar_t tmp1[MAX_SIZE];
		wchar_t tmp2[MAX_SIZE];
		wchar_t tmp4[MAX_SIZE];

		GetAccessListStr(tmp, sizeof(tmp), a);
		UniToStru(tmp1, a->Priority);
		StrToUni(tmp2, sizeof(tmp2), tmp);
		UniToStru(tmp4, a->UniqueId);
		if (a->UniqueId == 0)
		{
			UniStrCpy(tmp4, sizeof(tmp4), _UU("SEC_NONE"));
		}

		UniToStru(tmp3, a->Id);

		CtInsert(ct,
			tmp3,
			a->Discard ? _UU("SM_ACCESS_DISCARD") : _UU("SM_ACCESS_PASS"),
			a->Active ? _UU("SM_ACCESS_ENABLE") : _UU("SM_ACCESS_DISABLE"),
			tmp1,
			tmp4,
			tmp2,
			a->Note);
	}

	CtFreeEx(ct, c, true);

	FreeRpcEnumAccessList(&t);

	FreeParamValueList(o);

	return 0;
}