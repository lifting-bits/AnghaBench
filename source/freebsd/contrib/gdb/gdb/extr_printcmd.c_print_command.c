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
 int /*<<< orphan*/  print_command_1 (char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
print_command (char *exp, int from_tty)
{
  print_command_1 (exp, 0, 1);
}