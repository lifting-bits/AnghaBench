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
 int __GFP_FS ; 
 void* kmem_cache_alloc (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  zlib_workspace_cache ; 

__attribute__((used)) static void *
zlib_workspace_alloc(int flags)
{
	return (kmem_cache_alloc(zlib_workspace_cache, flags & ~(__GFP_FS)));
}