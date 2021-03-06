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
 int /*<<< orphan*/  kgdb_arch_init () ; 
 int kgdb_con_registered ; 
 int kgdb_io_module_registered ; 
 scalar_t__ kgdb_use_con ; 
 int /*<<< orphan*/  kgdbcons ; 
 int /*<<< orphan*/  register_console (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  register_sysrq_key (char,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysrq_gdb_op ; 

__attribute__((used)) static void kgdb_register_callbacks(void)
{
	if (!kgdb_io_module_registered) {
		kgdb_io_module_registered = 1;
		kgdb_arch_init();
#ifdef CONFIG_MAGIC_SYSRQ
		register_sysrq_key('g', &sysrq_gdb_op);
#endif
		if (kgdb_use_con && !kgdb_con_registered) {
			register_console(&kgdbcons);
			kgdb_con_registered = 1;
		}
	}
}