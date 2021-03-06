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
typedef  char xmlChar ;

/* Variables and functions */

__attribute__((used)) static int is_blank(const xmlChar* str)
{
	while (*str != '\0') {
		if (*str != ' '  && *str != 0x9 && *str != 0xa && *str != 0xd) {
			return 0;
		}
		str++;
	}
	return 1;
}