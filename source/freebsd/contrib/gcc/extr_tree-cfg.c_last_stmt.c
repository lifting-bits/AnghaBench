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
typedef  int /*<<< orphan*/  block_stmt_iterator ;
typedef  int /*<<< orphan*/  basic_block ;

/* Variables and functions */
 int /*<<< orphan*/  NULL_TREE ; 
 int /*<<< orphan*/  bsi_end_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bsi_last (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bsi_stmt (int /*<<< orphan*/ ) ; 

tree
last_stmt (basic_block bb)
{
  block_stmt_iterator b = bsi_last (bb);
  return !bsi_end_p (b) ? bsi_stmt (b) : NULL_TREE;
}