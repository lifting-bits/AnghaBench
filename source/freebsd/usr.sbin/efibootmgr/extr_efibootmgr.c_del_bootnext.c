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
 int /*<<< orphan*/  EFI_GLOBAL_GUID ; 
 scalar_t__ efi_del_variable (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  err (int,char*) ; 

__attribute__((used)) static void
del_bootnext(void)
{

	if (efi_del_variable(EFI_GLOBAL_GUID, "BootNext") < 0)
		err(1, "efi_del_variable");
}