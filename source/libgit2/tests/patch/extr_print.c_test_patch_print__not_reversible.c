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
 int /*<<< orphan*/  PATCH_BINARY_NOT_REVERSIBLE ; 
 int /*<<< orphan*/  patch_print_from_patchfile (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 

void test_patch_print__not_reversible(void)
{
	patch_print_from_patchfile(PATCH_BINARY_NOT_REVERSIBLE,
		strlen(PATCH_BINARY_NOT_REVERSIBLE));
}