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
 int /*<<< orphan*/  ngx_memory_barrier () ; 
 int /*<<< orphan*/  ngx_memzero (void*,size_t) ; 

void
ngx_explicit_memzero(void *buf, size_t n)
{
    ngx_memzero(buf, n);
    ngx_memory_barrier();
}