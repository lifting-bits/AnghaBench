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
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,size_t) ; 
 size_t lua_rawlen (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int
llen(lua_State *L) {
	size_t sz = lua_rawlen(L, 1);
	lua_pushinteger(L, sz);
	return 1;
}