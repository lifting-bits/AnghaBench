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
 int /*<<< orphan*/  DEFAULT_COLLATION_OID ; 
 int /*<<< orphan*/  pfree (char*) ; 
 char* str_tolower (char const*,size_t,int /*<<< orphan*/ ) ; 
 int strncmp (char*,char*,size_t) ; 

int
ltree_strncasecmp(const char *a, const char *b, size_t s)
{
	char	   *al = str_tolower(a, s, DEFAULT_COLLATION_OID);
	char	   *bl = str_tolower(b, s, DEFAULT_COLLATION_OID);
	int			res;

	res = strncmp(al, bl, s);

	pfree(al);
	pfree(bl);

	return res;
}