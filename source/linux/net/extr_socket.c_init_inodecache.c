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
struct socket_alloc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 int SLAB_ACCOUNT ; 
 int SLAB_HWCACHE_ALIGN ; 
 int SLAB_MEM_SPREAD ; 
 int SLAB_RECLAIM_ACCOUNT ; 
 int /*<<< orphan*/  init_once ; 
 int /*<<< orphan*/ * kmem_cache_create (char*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * sock_inode_cachep ; 

__attribute__((used)) static void init_inodecache(void)
{
	sock_inode_cachep = kmem_cache_create("sock_inode_cache",
					      sizeof(struct socket_alloc),
					      0,
					      (SLAB_HWCACHE_ALIGN |
					       SLAB_RECLAIM_ACCOUNT |
					       SLAB_MEM_SPREAD | SLAB_ACCOUNT),
					      init_once);
	BUG_ON(sock_inode_cachep == NULL);
}