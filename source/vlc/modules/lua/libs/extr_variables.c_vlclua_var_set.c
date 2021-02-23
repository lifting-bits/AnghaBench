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
typedef  int /*<<< orphan*/  vlc_value_t ;
typedef  int /*<<< orphan*/  vlc_object_t ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 char* luaL_checkstring (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ ** luaL_checkudata (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  lua_pop (int /*<<< orphan*/ *,int) ; 
 int var_Set (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int var_Type (int /*<<< orphan*/ *,char const*) ; 
 int vlclua_push_ret (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  vlclua_tovalue (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int vlclua_var_set( lua_State *L )
{
    vlc_value_t val;
    vlc_object_t **pp_obj = luaL_checkudata( L, 1, "vlc_object" );
    const char *psz_var = luaL_checkstring( L, 2 );

    int i_type = var_Type( *pp_obj, psz_var );
    vlclua_tovalue( L, i_type, &val );

    int i_ret = var_Set( *pp_obj, psz_var, val );

    lua_pop( L, 3 );
    return vlclua_push_ret( L, i_ret );
}