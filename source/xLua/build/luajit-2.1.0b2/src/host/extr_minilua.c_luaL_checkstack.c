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
 int /*<<< orphan*/  luaL_error (int /*<<< orphan*/ *,char*,char const*) ; 
 int /*<<< orphan*/  lua_checkstack (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void luaL_checkstack(lua_State*L,int space,const char*mes){
if(!lua_checkstack(L,space))
luaL_error(L,"stack overflow (%s)",mes);
}