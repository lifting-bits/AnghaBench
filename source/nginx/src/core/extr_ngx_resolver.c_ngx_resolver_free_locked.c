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
typedef  int /*<<< orphan*/  ngx_resolver_t ;

/* Variables and functions */
 int /*<<< orphan*/  ngx_free (void*) ; 

__attribute__((used)) static void
ngx_resolver_free_locked(ngx_resolver_t *r, void *p)
{
    ngx_free(p);
}