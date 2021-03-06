#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {struct TYPE_4__* right; struct TYPE_4__* left; } ;
typedef  TYPE_1__ privacy_t ;

/* Variables and functions */
 int /*<<< orphan*/  free_privacy_node (TYPE_1__*) ; 

__attribute__((used)) static void free_privacy_tree (privacy_t *T) {
  if (T) {
    free_privacy_tree (T->left);
    free_privacy_tree (T->right);
    free_privacy_node (T);
  }
}