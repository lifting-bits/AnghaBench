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
 int /*<<< orphan*/  GIT_UNUSED (void*) ; 
 int strcmp (char const*,char const*) ; 

__attribute__((used)) static int cmp_str(const void *_a, const void *_b, void *payload)
{
	GIT_UNUSED(payload);
	return strcmp((const char *) _a, (const char *) _b);
}