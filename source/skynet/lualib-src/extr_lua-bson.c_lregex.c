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
typedef  int /*<<< orphan*/  luaL_Buffer ;

/* Variables and functions */
 int /*<<< orphan*/  BSON_REGEX ; 
 int /*<<< orphan*/  luaL_addchar (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaL_addvalue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaL_buffinit (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaL_checkstring (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  luaL_pushresult (int /*<<< orphan*/ *) ; 
 int lua_gettop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_pushliteral (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lua_pushvalue (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int
lregex(lua_State *L) {
	luaL_checkstring(L,1);
	if (lua_gettop(L) < 2) {
		lua_pushliteral(L,"");
	}
	luaL_Buffer b;
	luaL_buffinit(L, &b);
	luaL_addchar(&b, 0);
	luaL_addchar(&b, BSON_REGEX);
	lua_pushvalue(L,1);
	luaL_addvalue(&b);
	luaL_addchar(&b,0);
	lua_pushvalue(L,2);
	luaL_addvalue(&b);
	luaL_addchar(&b,0);
	luaL_pushresult(&b);

	return 1;
}