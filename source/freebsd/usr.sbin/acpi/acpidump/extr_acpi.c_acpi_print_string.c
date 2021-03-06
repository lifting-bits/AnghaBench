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
 int /*<<< orphan*/  putchar (int) ; 

__attribute__((used)) static void
acpi_print_string(char *s, size_t length)
{
	int	c;

	/* Trim trailing spaces and NULLs */
	while (length > 0 && (s[length - 1] == ' ' || s[length - 1] == '\0'))
		length--;

	while (length--) {
		c = *s++;
		putchar(c);
	}
}