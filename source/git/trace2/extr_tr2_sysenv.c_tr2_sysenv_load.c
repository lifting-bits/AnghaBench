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
 scalar_t__ ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUG (char*) ; 
 scalar_t__ TR2_SYSENV_MUST_BE_LAST ; 
 int /*<<< orphan*/  read_very_early_config (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tr2_sysenv_cb ; 
 int /*<<< orphan*/  tr2_sysenv_settings ; 

void tr2_sysenv_load(void)
{
	if (ARRAY_SIZE(tr2_sysenv_settings) != TR2_SYSENV_MUST_BE_LAST)
		BUG("tr2_sysenv_settings size is wrong");

	read_very_early_config(tr2_sysenv_cb, NULL);
}