#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  x; } ;
typedef  TYPE_1__ tree_ext_small_t ;

/* Variables and functions */
 int b_out_rev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int ctree_out_node_rev (tree_ext_small_t *T) {
  return b_out_rev (T->x);
}