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
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  luaT_newmetatable (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaT_setfuncs (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  torch_Timer__ ; 
 int /*<<< orphan*/  torch_Timer_free ; 
 int /*<<< orphan*/  torch_Timer_new ; 

void torch_Timer_init(lua_State *L)
{
  luaT_newmetatable(L, "torch.Timer", NULL, torch_Timer_new, torch_Timer_free, NULL);
  luaT_setfuncs(L, torch_Timer__, 0);
  lua_pop(L, 1);
}