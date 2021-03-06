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
struct malloc_type {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bcopy (char const*,char*,size_t) ; 
 char* malloc (size_t,struct malloc_type*,int) ; 
 int strlen (char const*) ; 

char *
strdup_flags(const char *string, struct malloc_type *type, int flags)
{
	size_t len;
	char *copy;

	len = strlen(string) + 1;
	copy = malloc(len, type, flags);
	if (copy == NULL)
		return (NULL);
	bcopy(string, copy, len);
	return (copy);
}