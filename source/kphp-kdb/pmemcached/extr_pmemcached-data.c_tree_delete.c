#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {struct TYPE_9__* right; struct TYPE_9__* left; int /*<<< orphan*/  x; } ;
typedef  TYPE_1__ tree_t ;
typedef  int /*<<< orphan*/  hash_entry_t ;

/* Variables and functions */
 int /*<<< orphan*/  assert (TYPE_1__*) ; 
 int /*<<< orphan*/  free_tree_node (TYPE_1__*) ; 
 int node_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_1__* tree_merge (TYPE_1__*,TYPE_1__*) ; 

__attribute__((used)) static tree_t *tree_delete (tree_t *T, hash_entry_t *x) {
  int c;
  assert (T);
  if (!(c = node_cmp (x, T->x))) {
    tree_t *N = tree_merge (T->left, T->right);
    free_tree_node (T);
    return N;
  }
  if (c < 0) {
    T->left = tree_delete (T->left, x);
  } else {
    T->right = tree_delete (T->right, x);
  }
  return T;
}