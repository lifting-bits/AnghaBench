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
 int /*<<< orphan*/  TREE_CONSTANT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TREE_TYPE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TYPE_SIZE_UNIT (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool
is_variable_sized (tree expr)
{
  return !TREE_CONSTANT (TYPE_SIZE_UNIT (TREE_TYPE (expr)));
}