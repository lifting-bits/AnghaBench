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
struct kmem_cache {int flags; scalar_t__ ctor; } ;

/* Variables and functions */
 int SLAB_POISON ; 
 int SLAB_TYPESAFE_BY_RCU ; 
 int /*<<< orphan*/  init_on_free ; 
 scalar_t__ static_branch_unlikely (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool slab_want_init_on_free(struct kmem_cache *c)
{
	if (static_branch_unlikely(&init_on_free))
		return !(c->ctor ||
			 (c->flags & (SLAB_TYPESAFE_BY_RCU | SLAB_POISON)));
	return false;
}