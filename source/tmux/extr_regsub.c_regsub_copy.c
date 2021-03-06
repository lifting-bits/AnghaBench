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
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 char* xrealloc (char*,size_t) ; 

__attribute__((used)) static void
regsub_copy(char **buf, size_t *len, const char *text, size_t start,
    size_t end)
{
	size_t	add = end - start;

	*buf = xrealloc(*buf, (*len) + add + 1);
	memcpy((*buf) + *len, text + start, add);
	(*len) += add;
}