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
 int /*<<< orphan*/  is_in_name (char const) ; 
 int /*<<< orphan*/  is_name (char const) ; 

int
isassignment(const char *p)
{
	if (!is_name(*p))
		return 0;
	p++;
	for (;;) {
		if (*p == '=')
			return 1;
		else if (!is_in_name(*p))
			return 0;
		p++;
	}
}