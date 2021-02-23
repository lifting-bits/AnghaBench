#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {scalar_t__ nactvar; int /*<<< orphan*/  breaklist; scalar_t__ upval; int /*<<< orphan*/  isbreakable; struct TYPE_7__* previous; } ;
struct TYPE_6__ {scalar_t__ nactvar; scalar_t__ freereg; int /*<<< orphan*/  ls; TYPE_2__* bl; } ;
typedef  TYPE_1__ FuncState ;
typedef  TYPE_2__ BlockCnt ;

/* Variables and functions */
 int /*<<< orphan*/  OP_CLOSE ; 
 int /*<<< orphan*/  luaK_codeABC (TYPE_1__*,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaK_patchtohere (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_assert (int) ; 
 int /*<<< orphan*/  removevars (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void leaveblock (FuncState *fs) {
  BlockCnt *bl = fs->bl;
  fs->bl = bl->previous;
  removevars(fs->ls, bl->nactvar);
  if (bl->upval)
    luaK_codeABC(fs, OP_CLOSE, bl->nactvar, 0, 0);
  /* a block either controls scope or breaks (never both) */
  lua_assert(!bl->isbreakable || !bl->upval);
  lua_assert(bl->nactvar == fs->nactvar);
  fs->freereg = fs->nactvar;  /* free registers */
  luaK_patchtohere(fs, bl->breaklist);
}