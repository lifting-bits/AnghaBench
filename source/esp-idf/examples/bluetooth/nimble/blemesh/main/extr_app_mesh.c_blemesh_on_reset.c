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

/* Variables and functions */
 int /*<<< orphan*/  BLE_HS_LOG (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  ERROR ; 

__attribute__((used)) static void
blemesh_on_reset(int reason)
{
    BLE_HS_LOG(ERROR, "Resetting state; reason=%d\n", reason);
}