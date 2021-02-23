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
struct script_ctx {int /*<<< orphan*/  client; } ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  MPV_FORMAT_FLAG ; 
 int check_error (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct script_ctx* get_ctx (int /*<<< orphan*/ *) ; 
 char* luaL_checkstring (int /*<<< orphan*/ *,int) ; 
 int lua_toboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mpv_set_property (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int script_set_property_bool(lua_State *L)
{
    struct script_ctx *ctx = get_ctx(L);
    const char *p = luaL_checkstring(L, 1);
    int v = lua_toboolean(L, 2);

    return check_error(L, mpv_set_property(ctx->client, p, MPV_FORMAT_FLAG, &v));
}