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
 int /*<<< orphan*/  ls_get_libobs_obj (int,int,int*) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_rawgeti (int /*<<< orphan*/ *,int,int) ; 
 size_t lua_rawlen (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  obs_source_release (int) ; 
 int obs_source_t ; 
 int source ; 

__attribute__((used)) static int source_list_release(lua_State *script)
{
	size_t count = lua_rawlen(script, 1);
	for (size_t i = 0; i < count; i++) {
		obs_source_t *source;

		lua_rawgeti(script, 1, (int)i + 1);
		ls_get_libobs_obj(obs_source_t, -1, &source);
		lua_pop(script, 1);

		obs_source_release(source);
	}
	return 0;
}