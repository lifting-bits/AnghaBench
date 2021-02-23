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
typedef  int /*<<< orphan*/  tree_num_t ;

/* Variables and functions */
 int /*<<< orphan*/ * NIL ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  zfree (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void free_tree_num_node (tree_num_t *T) {
  assert (T != NIL);
  zfree (T, sizeof (tree_num_t));
}