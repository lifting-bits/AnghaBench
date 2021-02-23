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
typedef  size_t UINT ;
struct TYPE_5__ {size_t NumItem; TYPE_1__* Items; } ;
struct TYPE_4__ {int /*<<< orphan*/  SerialId; int /*<<< orphan*/  SystemId; int /*<<< orphan*/  ProductId; int /*<<< orphan*/  Status; int /*<<< orphan*/  Expires; int /*<<< orphan*/  LicenseName; int /*<<< orphan*/  LicenseId; int /*<<< orphan*/  LicenseKey; int /*<<< orphan*/  Id; } ;
typedef  TYPE_1__ RPC_ENUM_LICENSE_KEY_ITEM ;
typedef  TYPE_2__ RPC_ENUM_LICENSE_KEY ;
typedef  int /*<<< orphan*/  PACK ;

/* Variables and functions */
 int /*<<< orphan*/  PackAddInt (int /*<<< orphan*/ *,char*,size_t) ; 
 int /*<<< orphan*/  PackAddInt64Ex (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,size_t,size_t) ; 
 int /*<<< orphan*/  PackAddIntEx (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,size_t,size_t) ; 
 int /*<<< orphan*/  PackAddStrEx (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,size_t,size_t) ; 
 int /*<<< orphan*/  PackAddTime64Ex (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,size_t,size_t) ; 
 int /*<<< orphan*/  PackSetCurrentJsonGroupName (int /*<<< orphan*/ *,char*) ; 

void OutRpcEnumLicenseKey(PACK *p, RPC_ENUM_LICENSE_KEY *t)
{
	UINT i;
	// Validate arguments
	if (t == NULL || p == NULL)
	{
		return;
	}

	PackAddInt(p, "NumItem", t->NumItem);

	PackSetCurrentJsonGroupName(p, "LicenseKeyList");
	for (i = 0;i < t->NumItem;i++)
	{
		RPC_ENUM_LICENSE_KEY_ITEM *e = &t->Items[i];

		PackAddIntEx(p, "Id", e->Id, i, t->NumItem);
		PackAddStrEx(p, "LicenseKey", e->LicenseKey, i, t->NumItem);
		PackAddStrEx(p, "LicenseId", e->LicenseId, i, t->NumItem);
		PackAddStrEx(p, "LicenseName", e->LicenseName, i, t->NumItem);
		PackAddTime64Ex(p, "Expires", e->Expires, i, t->NumItem);
		PackAddIntEx(p, "Status", e->Status, i, t->NumItem);
		PackAddIntEx(p, "ProductId", e->ProductId, i, t->NumItem);
		PackAddInt64Ex(p, "SystemId", e->SystemId, i, t->NumItem);
		PackAddIntEx(p, "SerialId", e->SerialId, i, t->NumItem);
	}
	PackSetCurrentJsonGroupName(p, NULL);
}