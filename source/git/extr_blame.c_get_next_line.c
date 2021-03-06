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
 char* memchr (char const*,char,int) ; 

__attribute__((used)) static const char *get_next_line(const char *start, const char *end)
{
	const char *nl = memchr(start, '\n', end - start);

	return nl ? nl + 1 : end;
}