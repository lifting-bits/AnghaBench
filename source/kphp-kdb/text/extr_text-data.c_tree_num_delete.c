#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int x; struct TYPE_10__* right; struct TYPE_10__* left; } ;
typedef  TYPE_1__ tree_num_t ;

/* Variables and functions */
 TYPE_1__* NIL ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  free_tree_num_node (TYPE_1__*) ; 
 TYPE_1__* tree_num_merge (TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  tree_num_relax (TYPE_1__*) ; 

__attribute__((used)) static tree_num_t *tree_num_delete (tree_num_t *T, int x) {
  assert (T != NIL);
  if (T->x == x) {
    tree_num_t *N = tree_num_merge (T->left, T->right);
    free_tree_num_node (T);
    return N;
  }
  if (x < T->x) {
    T->left = tree_num_delete (T->left, x);
  } else {
    T->right = tree_num_delete (T->right, x);
  }
  tree_num_relax (T);
  return T;
}