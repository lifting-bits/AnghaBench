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
struct TYPE_4__ {int Enabled; int /*<<< orphan*/  Guid; int /*<<< orphan*/  FileName; int /*<<< orphan*/  Version; int /*<<< orphan*/  MacAddress; int /*<<< orphan*/  DeviceName; } ;
typedef  TYPE_1__ RPC_CLIENT_GET_VLAN ;
typedef  int /*<<< orphan*/  PACK ;

/* Variables and functions */
 scalar_t__ PackGetInt (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  PackGetStr (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  Zero (TYPE_1__*,int) ; 

void InRpcClientGetVLan(RPC_CLIENT_GET_VLAN *v, PACK *p)
{
	// Validate arguments
	if (v == NULL || p == NULL)
	{
		return;
	}

	Zero(v, sizeof(RPC_CLIENT_GET_VLAN));
	PackGetStr(p, "DeviceName", v->DeviceName, sizeof(v->DeviceName));
	v->Enabled = PackGetInt(p, "Enabled") ? true : false;
	PackGetStr(p, "MacAddress", v->MacAddress, sizeof(v->MacAddress));
	PackGetStr(p, "Version", v->Version, sizeof(v->Version));
	PackGetStr(p, "FileName", v->FileName, sizeof(v->FileName));
	PackGetStr(p, "Guid", v->Guid, sizeof(v->Guid));
}