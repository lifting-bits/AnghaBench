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
 int /*<<< orphan*/  LUA_REGISTRYINDEX ; 
 scalar_t__ luaT_pushmetatable (int /*<<< orphan*/ *,char const*) ; 
 scalar_t__ lua_isstring (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_rawget (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 char* lua_tostring (int /*<<< orphan*/ *,int) ; 

const char *luaT_typenameid(lua_State *L, const char *tname)
{
  if(luaT_pushmetatable(L, tname))
  {
    const char *tnameid = NULL;
    lua_rawget(L, LUA_REGISTRYINDEX);
    if(lua_isstring(L, -1))
      tnameid = lua_tostring(L, -1);
    lua_pop(L, 1); /* the string/nil */
    return tnameid;
  }
  return NULL;
}