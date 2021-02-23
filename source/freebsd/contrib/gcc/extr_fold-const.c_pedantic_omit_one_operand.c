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
typedef  int /*<<< orphan*/  tree ;

/* Variables and functions */
 int /*<<< orphan*/  COMPOUND_EXPR ; 
 scalar_t__ TREE_SIDE_EFFECTS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  build2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fold_convert (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fold_ignored_result (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pedantic_non_lvalue (int /*<<< orphan*/ ) ; 

__attribute__((used)) static tree
pedantic_omit_one_operand (tree type, tree result, tree omitted)
{
  tree t = fold_convert (type, result);

  if (TREE_SIDE_EFFECTS (omitted))
    return build2 (COMPOUND_EXPR, type, fold_ignored_result (omitted), t);

  return pedantic_non_lvalue (t);
}