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
 char* heap_alloc (scalar_t__) ; 
 char* lstrcpyA (char*,char const*) ; 
 scalar_t__ lstrlenA (char const*) ; 

__attribute__((used)) static inline char *RTFStrSave(const char *s)
{
	char	*p;

	p = heap_alloc (lstrlenA(s) + 1);
	if (p == NULL)
		return NULL;
	return lstrcpyA (p, s);
}