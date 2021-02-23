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
 int /*<<< orphan*/  efunc (int,char*,size_t) ; 
 void* realloc (void*,size_t) ; 
 int /*<<< orphan*/  stub1 (int,char*,size_t) ; 

void *
erealloc(void *p, size_t n)
{
	void *q = realloc(p, n);
	if (q == NULL && n != 0)
		(*efunc)(1, "Cannot re-allocate %zu bytes", n);
	return q;
}