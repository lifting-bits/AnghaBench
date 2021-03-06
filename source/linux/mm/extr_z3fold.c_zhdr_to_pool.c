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
struct z3fold_pool {int dummy; } ;
struct z3fold_header {struct z3fold_pool* pool; } ;

/* Variables and functions */

__attribute__((used)) static inline struct z3fold_pool *zhdr_to_pool(struct z3fold_header *zhdr)
{
	return zhdr->pool;
}