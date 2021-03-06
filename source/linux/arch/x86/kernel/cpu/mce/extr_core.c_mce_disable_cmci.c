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
 int /*<<< orphan*/  cmci_clear () ; 
 int /*<<< orphan*/  cpu_info ; 
 int /*<<< orphan*/  mce_available (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  raw_cpu_ptr (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mce_disable_cmci(void *data)
{
	if (!mce_available(raw_cpu_ptr(&cpu_info)))
		return;
	cmci_clear();
}