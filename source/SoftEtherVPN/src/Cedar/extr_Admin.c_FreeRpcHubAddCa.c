#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  Cert; } ;
typedef  TYPE_1__ RPC_HUB_ADD_CA ;

/* Variables and functions */
 int /*<<< orphan*/  FreeX (int /*<<< orphan*/ ) ; 

void FreeRpcHubAddCa(RPC_HUB_ADD_CA *t)
{
	// Validate arguments
	if (t == NULL)
	{
		return;
	}

	FreeX(t->Cert);
}