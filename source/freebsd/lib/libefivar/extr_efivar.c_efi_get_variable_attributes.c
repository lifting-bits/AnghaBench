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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  efi_guid_t ;

/* Variables and functions */
 int efi_get_variable (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int
efi_get_variable_attributes(efi_guid_t guid, const char *name,
    uint32_t *attributes)
{
	/* Make sure this construct works -- I think it will fail */

	return efi_get_variable(guid, name, NULL, NULL, attributes);
}