#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  tmp3 ;
typedef  int /*<<< orphan*/  tmp2 ;
typedef  int /*<<< orphan*/  tmp1 ;
typedef  int /*<<< orphan*/  t ;
typedef  int /*<<< orphan*/  args ;
typedef  scalar_t__ UINT ;
struct TYPE_12__ {char* member_0; int /*<<< orphan*/ * member_4; int /*<<< orphan*/  member_3; int /*<<< orphan*/  member_2; int /*<<< orphan*/  member_1; } ;
struct TYPE_11__ {int /*<<< orphan*/  Rpc; } ;
struct TYPE_10__ {scalar_t__ NumItem; TYPE_1__* Items; int /*<<< orphan*/  Name; } ;
struct TYPE_9__ {int /*<<< orphan*/  Metric; int /*<<< orphan*/  GatewayAddress; int /*<<< orphan*/  SubnetMask; int /*<<< orphan*/  NetworkAddress; } ;
typedef  TYPE_1__ RPC_L3TABLE ;
typedef  TYPE_2__ RPC_ENUM_L3TABLE ;
typedef  TYPE_3__ PS ;
typedef  TYPE_4__ PARAM ;
typedef  int /*<<< orphan*/  LIST ;
typedef  int /*<<< orphan*/  CT ;
typedef  int /*<<< orphan*/  CONSOLE ;

/* Variables and functions */
 int /*<<< orphan*/  CmdEvalNotEmpty ; 
 int /*<<< orphan*/  CmdPrintError (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  CmdPrompt ; 
 int /*<<< orphan*/  CtFree (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CtInsert (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CtInsertColumn (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * CtNew () ; 
 scalar_t__ ERR_INVALID_PARAMETER ; 
 scalar_t__ ERR_NO_ERROR ; 
 int /*<<< orphan*/  FreeParamValueList (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FreeRpcEnumL3Table (TYPE_2__*) ; 
 int /*<<< orphan*/  GetParamStr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  IPToUniStr32 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int MAX_SIZE ; 
 int /*<<< orphan*/ * ParseCommandList (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,TYPE_4__*,int) ; 
 scalar_t__ ScEnumL3Table (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  StrCpy (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UniToStru (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Zero (TYPE_2__*,int) ; 
 int /*<<< orphan*/  _UU (char*) ; 

UINT PsRouterTableList(CONSOLE *c, char *cmd_name, wchar_t *str, void *param)
{
	LIST *o;
	PS *ps = (PS *)param;
	UINT ret = 0;
	RPC_ENUM_L3TABLE t;
	CT *ct;
	wchar_t tmp1[MAX_SIZE];
	wchar_t tmp2[MAX_SIZE];
	wchar_t tmp3[MAX_SIZE];
	wchar_t tmp4[MAX_SIZE];
	// Parameter list that can be specified
	PARAM args[] =
	{
		{"[name]", CmdPrompt, _UU("CMD_RouterTableList_PROMPT_NAME"), CmdEvalNotEmpty, NULL},
	};

	o = ParseCommandList(c, cmd_name, str, args, sizeof(args) / sizeof(args[0]));
	if (o == NULL)
	{
		return ERR_INVALID_PARAMETER;
	}

	Zero(&t, sizeof(t));

	StrCpy(t.Name, sizeof(t.Name), GetParamStr(o, "[name]"));

	// RPC call
	ret = ScEnumL3Table(ps->Rpc, &t);

	if (ret != ERR_NO_ERROR)
	{
		// An error has occured
		CmdPrintError(c, ret);
		FreeParamValueList(o);
		return ret;
	}
	else
	{
		UINT i;

		ct = CtNew();

		CtInsertColumn(ct, _UU("SM_L3_SW_TABLE_COLUMN1"), false);
		CtInsertColumn(ct, _UU("SM_L3_SW_TABLE_COLUMN2"), false);
		CtInsertColumn(ct, _UU("SM_L3_SW_TABLE_COLUMN3"), false);
		CtInsertColumn(ct, _UU("SM_L3_SW_TABLE_COLUMN4"), true);

		for (i = 0;i < t.NumItem;i++)
		{
			RPC_L3TABLE *e = &t.Items[i];

			IPToUniStr32(tmp1, sizeof(tmp1), e->NetworkAddress);
			IPToUniStr32(tmp2, sizeof(tmp2), e->SubnetMask);
			IPToUniStr32(tmp3, sizeof(tmp3), e->GatewayAddress);
			UniToStru(tmp4, e->Metric);

			CtInsert(ct, tmp1, tmp2, tmp3, tmp4);
		}

		CtFree(ct, c);
	}

	FreeRpcEnumL3Table(&t);

	FreeParamValueList(o);

	return 0;
}