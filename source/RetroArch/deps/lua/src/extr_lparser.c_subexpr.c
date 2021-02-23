#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  expdesc ;
typedef  scalar_t__ UnOpr ;
struct TYPE_11__ {int left; int right; } ;
struct TYPE_9__ {int /*<<< orphan*/  token; } ;
struct TYPE_10__ {int linenumber; int /*<<< orphan*/  fs; TYPE_1__ t; } ;
typedef  TYPE_2__ LexState ;
typedef  size_t BinOpr ;

/* Variables and functions */
 size_t OPR_NOBINOPR ; 
 scalar_t__ OPR_NOUNOPR ; 
 int UNARY_PRIORITY ; 
 int /*<<< orphan*/  enterlevel (TYPE_2__*) ; 
 size_t getbinopr (int /*<<< orphan*/ ) ; 
 scalar_t__ getunopr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  leavelevel (TYPE_2__*) ; 
 int /*<<< orphan*/  luaK_infix (int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaK_posfix (int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  luaK_prefix (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  luaX_next (TYPE_2__*) ; 
 TYPE_5__* priority ; 
 int /*<<< orphan*/  simpleexp (TYPE_2__*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static BinOpr subexpr (LexState *ls, expdesc *v, int limit) {
  BinOpr op;
  UnOpr uop;
  enterlevel(ls);
  uop = getunopr(ls->t.token);
  if (uop != OPR_NOUNOPR) {
    int line = ls->linenumber;
    luaX_next(ls);
    subexpr(ls, v, UNARY_PRIORITY);
    luaK_prefix(ls->fs, uop, v, line);
  }
  else simpleexp(ls, v);
  /* expand while operators have priorities higher than 'limit' */
  op = getbinopr(ls->t.token);
  while (op != OPR_NOBINOPR && priority[op].left > limit) {
    expdesc v2;
    BinOpr nextop;
    int line = ls->linenumber;
    luaX_next(ls);
    luaK_infix(ls->fs, op, v);
    /* read sub-expression with higher priority */
    nextop = subexpr(ls, &v2, priority[op].right);
    luaK_posfix(ls->fs, op, v, &v2, line);
    op = nextop;
  }
  leavelevel(ls);
  return op;  /* return first untreated operator */
}