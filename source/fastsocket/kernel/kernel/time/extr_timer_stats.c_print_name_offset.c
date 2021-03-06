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
struct seq_file {int dummy; } ;

/* Variables and functions */
 int KSYM_NAME_LEN ; 
 scalar_t__ lookup_symbol_name (unsigned long,char*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,char*) ; 

__attribute__((used)) static void print_name_offset(struct seq_file *m, unsigned long addr)
{
	char symname[KSYM_NAME_LEN];

	if (lookup_symbol_name(addr, symname) < 0)
		seq_printf(m, "<%p>", (void *)addr);
	else
		seq_printf(m, "%s", symname);
}