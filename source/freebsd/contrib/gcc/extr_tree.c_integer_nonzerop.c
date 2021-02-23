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
 scalar_t__ COMPLEX_CST ; 
 scalar_t__ INTEGER_CST ; 
 int /*<<< orphan*/  STRIP_NOPS (int /*<<< orphan*/ ) ; 
 scalar_t__ TREE_CODE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TREE_IMAGPART (int /*<<< orphan*/ ) ; 
 scalar_t__ TREE_INT_CST_HIGH (int /*<<< orphan*/ ) ; 
 scalar_t__ TREE_INT_CST_LOW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TREE_REALPART (int /*<<< orphan*/ ) ; 

int
integer_nonzerop (tree expr)
{
  STRIP_NOPS (expr);

  return ((TREE_CODE (expr) == INTEGER_CST
	   && (TREE_INT_CST_LOW (expr) != 0
	       || TREE_INT_CST_HIGH (expr) != 0))
	  || (TREE_CODE (expr) == COMPLEX_CST
	      && (integer_nonzerop (TREE_REALPART (expr))
		  || integer_nonzerop (TREE_IMAGPART (expr)))));
}