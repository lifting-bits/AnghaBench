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
 char* LUA_DIRSEP ; 
 int /*<<< orphan*/  luaL_checkstring (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  luaL_optstring (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  lua_insert (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushnil (int /*<<< orphan*/ *) ; 
 char* searchpath (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int lj_cf_package_searchpath(lua_State *L)
{
  const char *f = searchpath(L, luaL_checkstring(L, 1),
				luaL_checkstring(L, 2),
				luaL_optstring(L, 3, "."),
				luaL_optstring(L, 4, LUA_DIRSEP));
  if (f != NULL) {
    return 1;
  } else {  /* error message is on top of the stack */
    lua_pushnil(L);
    lua_insert(L, -2);
    return 2;  /* return nil + error message */
  }
}