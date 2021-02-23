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
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */
 void* do_scavenging_realloc (int /*<<< orphan*/ *,void*,size_t) ; 
 int /*<<< orphan*/  fz_free (int /*<<< orphan*/ *,void*) ; 

void *
fz_realloc_no_throw(fz_context *ctx, void *p, size_t size)
{
	if (size == 0)
	{
		fz_free(ctx, p);
		return NULL;
	}
	return do_scavenging_realloc(ctx, p, size);
}