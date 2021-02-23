#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/ * ci; int /*<<< orphan*/  base_ci; } ;
typedef  TYPE_1__ lua_State ;

/* Variables and functions */
 int LUA_YIELD ; 
 int /*<<< orphan*/  finishCcall (TYPE_1__*,int) ; 
 int /*<<< orphan*/  isLua (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaV_execute (TYPE_1__*) ; 
 int /*<<< orphan*/  luaV_finishOp (TYPE_1__*) ; 

__attribute__((used)) static void unroll (lua_State *L, void *ud) {
  if (ud != NULL)  /* error status? */
    finishCcall(L, *(int *)ud);  /* finish 'lua_pcallk' callee */
  while (L->ci != &L->base_ci) {  /* something in the stack */
    if (!isLua(L->ci))  /* C function? */
      finishCcall(L, LUA_YIELD);  /* complete its execution */
    else {  /* Lua function */
      luaV_finishOp(L);  /* finish interrupted instruction */
      luaV_execute(L);  /* execute down to higher C 'boundary' */
    }
  }
}