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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int foreach_key (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  io_fprintf (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  save_option_keybinding ; 

__attribute__((used)) static bool
save_option_keybindings(FILE *file)
{
	if (!io_fprintf(file, "%s", "\n\n## Keybindings\n"))
		return false;

	return foreach_key(save_option_keybinding, file, false);
}