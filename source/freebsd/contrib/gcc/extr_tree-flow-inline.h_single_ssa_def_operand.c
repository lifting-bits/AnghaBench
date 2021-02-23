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
typedef  int /*<<< orphan*/  ssa_op_iter ;
typedef  int /*<<< orphan*/  def_operand_p ;

/* Variables and functions */
 int /*<<< orphan*/  NULL_DEF_OPERAND_P ; 
 scalar_t__ op_iter_done (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  op_iter_init_def (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  op_iter_next_def (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline def_operand_p
single_ssa_def_operand (tree stmt, int flags)
{
  def_operand_p var;
  ssa_op_iter iter;

  var = op_iter_init_def (&iter, stmt, flags);
  if (op_iter_done (&iter))
    return NULL_DEF_OPERAND_P;
  op_iter_next_def (&iter);
  if (op_iter_done (&iter))
    return var;
  return NULL_DEF_OPERAND_P;
}