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
 int CHAR_MAX ; 
 int strtol (char const*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static char
cnv(const char *str)
{
	int i = strtol(str, NULL, 10);

	if (i == -1)
		i = CHAR_MAX;
	return ((char)i);
}