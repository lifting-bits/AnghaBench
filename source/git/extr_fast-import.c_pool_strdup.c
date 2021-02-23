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
 int /*<<< orphan*/  fi_mem_pool ; 
 char* mem_pool_alloc (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 int strlen (char const*) ; 

__attribute__((used)) static char *pool_strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	char *r = mem_pool_alloc(&fi_mem_pool, len);
	memcpy(r, s, len);
	return r;
}