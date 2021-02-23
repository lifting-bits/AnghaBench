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
struct lua_obs_callback {int dummy; } ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 struct lua_obs_callback* find_lua_obs_callback (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  is_function ; 
 int /*<<< orphan*/  remove_lua_obs_callback (struct lua_obs_callback*) ; 
 int /*<<< orphan*/  verify_args1 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int obs_lua_remove_tick_callback(lua_State *script)
{
	if (!verify_args1(script, is_function))
		return 0;

	struct lua_obs_callback *cb = find_lua_obs_callback(script, 1);
	if (cb)
		remove_lua_obs_callback(cb);
	return 0;
}