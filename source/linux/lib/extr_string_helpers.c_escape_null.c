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

__attribute__((used)) static bool escape_null(unsigned char c, char **dst, char *end)
{
	char *out = *dst;

	if (c)
		return false;

	if (out < end)
		*out = '\\';
	++out;
	if (out < end)
		*out = '0';
	++out;

	*dst = out;
	return true;
}