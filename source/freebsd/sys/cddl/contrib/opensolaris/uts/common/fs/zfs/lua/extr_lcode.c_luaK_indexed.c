#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {scalar_t__ vt; int /*<<< orphan*/  idx; int /*<<< orphan*/  t; } ;
struct TYPE_9__ {TYPE_1__ ind; int /*<<< orphan*/  info; } ;
struct TYPE_10__ {scalar_t__ k; TYPE_2__ u; } ;
typedef  TYPE_3__ expdesc ;
typedef  int /*<<< orphan*/  FuncState ;

/* Variables and functions */
 scalar_t__ VINDEXED ; 
 int /*<<< orphan*/  VLOCAL ; 
 scalar_t__ VUPVAL ; 
 scalar_t__ check_exp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hasjumps (TYPE_3__*) ; 
 int /*<<< orphan*/  luaK_exp2RK (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  lua_assert (int) ; 
 int /*<<< orphan*/  vkisinreg (scalar_t__) ; 

void luaK_indexed (FuncState *fs, expdesc *t, expdesc *k) {
  lua_assert(!hasjumps(t));
  t->u.ind.t = t->u.info;
  t->u.ind.idx = luaK_exp2RK(fs, k);
  t->u.ind.vt = (t->k == VUPVAL) ? VUPVAL
                                 : check_exp(vkisinreg(t->k), VLOCAL);
  t->k = VINDEXED;
}