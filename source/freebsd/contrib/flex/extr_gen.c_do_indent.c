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
 int indent_level ; 
 int /*<<< orphan*/  outc (char) ; 

void do_indent ()
{
	int i = indent_level * 8;

	while (i >= 8) {
		outc ('\t');
		i -= 8;
	}

	while (i > 0) {
		outc (' ');
		--i;
	}
}