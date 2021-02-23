#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t UINT ;
struct TYPE_7__ {int NumItem; int /*<<< orphan*/  IsLicenseSupported; TYPE_1__* Items; } ;
struct TYPE_6__ {int /*<<< orphan*/  Active; int /*<<< orphan*/  DeviceName; } ;
typedef  TYPE_1__ RPC_ENUM_DEVICE_ITEM ;
typedef  TYPE_2__ RPC_ENUM_DEVICE ;
typedef  int /*<<< orphan*/  PACK ;

/* Variables and functions */
 int /*<<< orphan*/  PackGetBool (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  PackGetBoolEx (int /*<<< orphan*/ *,char*,size_t) ; 
 int PackGetInt (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  PackGetStrEx (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int,size_t) ; 
 int /*<<< orphan*/  Zero (TYPE_2__*,int) ; 
 TYPE_1__* ZeroMalloc (int) ; 

void InRpcEnumDevice(RPC_ENUM_DEVICE *t, PACK *p)
{
	UINT i;
	// Validate arguments
	if (t == NULL || p == NULL)
	{
		return;
	}

	Zero(t, sizeof(RPC_ENUM_DEVICE));
	t->NumItem = PackGetInt(p, "NumItem");
	t->Items = ZeroMalloc(sizeof(RPC_ENUM_DEVICE_ITEM) * t->NumItem);

	for (i = 0;i < t->NumItem;i++)
	{
		RPC_ENUM_DEVICE_ITEM *d = &t->Items[i];

		PackGetStrEx(p, "DeviceName", d->DeviceName, sizeof(d->DeviceName), i);
		d->Active = PackGetBoolEx(p, "Active", i);
	}

	t->IsLicenseSupported = PackGetBool(p, "IsLicenseSupported");
}