#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  vector; } ;
typedef  TYPE_1__ SubspaceStoreInternalNode ;

/* Variables and functions */
 int /*<<< orphan*/  pfree (void*) ; 
 int /*<<< orphan*/  ts_dimension_vec_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
subspace_store_internal_node_free(void *node)
{
	ts_dimension_vec_free(((SubspaceStoreInternalNode *) node)->vector);
	pfree(node);
}