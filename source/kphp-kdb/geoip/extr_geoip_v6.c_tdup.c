#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct tree {int level; scalar_t__ text; TYPE_2__* left; TYPE_1__* right; int /*<<< orphan*/  num; } ;
struct TYPE_4__ {int level; scalar_t__ extra; scalar_t__ text; scalar_t__ right; scalar_t__ left; int /*<<< orphan*/  num; } ;
struct TYPE_3__ {int level; scalar_t__ extra; scalar_t__ text; scalar_t__ right; scalar_t__ left; int /*<<< orphan*/  num; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ deg2 (int) ; 
 void* malloc (int) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ *,int) ; 
 int total ; 

void tdup (struct tree* tree) {
  assert (!tree->left);
  assert (!tree->right);
  assert (tree->level < 128);
  //assert (tree->text == -1);
  tree->left = malloc (sizeof (struct tree));
  tree->left->num = tree->num;
  tree->left->level = tree->level + 1;
  tree->left->left = 0;
  tree->left->right = 0;
  tree->left->extra = 0;
  tree->left->text = tree->text;
  tree->left->extra = deg2 (127 - tree->level);
  tree->right = malloc (sizeof (struct tree));
  tree->right->num = tree->num; 
  set_bit (&tree->right->num, 127 - tree->level);
  //+ (1 << (31 - tree->level));
  tree->right->level = tree->level + 1;
  tree->right->left = 0;
  tree->right->right = 0;
  tree->right->extra = 0;
  tree->right->text = tree->text;
  tree->right->extra = tree->left->extra;
  tree->text = 0;
  total += 2;
}