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
 int /*<<< orphan*/  flush_dcache_all () ; 
 int /*<<< orphan*/  flush_icache_all () ; 

__attribute__((used)) static void sh4_flush_cache_all(void *unused)
{
	flush_dcache_all();
	flush_icache_all();
}