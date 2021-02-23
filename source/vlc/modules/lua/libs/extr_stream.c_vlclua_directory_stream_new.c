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
typedef  int /*<<< orphan*/  vlc_object_t ;
typedef  int /*<<< orphan*/  stream_t ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 scalar_t__ VLC_SUCCESS ; 
 char* luaL_checkstring (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  vlc_stream_Delete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * vlc_stream_NewURL (int /*<<< orphan*/ *,char const*) ; 
 scalar_t__ vlc_stream_directory_Attach (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int vlclua_error (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * vlclua_get_this (int /*<<< orphan*/ *) ; 
 int vlclua_stream_new_inner (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int vlclua_directory_stream_new( lua_State *L )
{
    vlc_object_t * p_this = vlclua_get_this( L );
    const char * psz_url = luaL_checkstring( L, 1 );
    stream_t *p_stream = vlc_stream_NewURL( p_this, psz_url );
    if( !p_stream )
        return vlclua_error( L );
    if( vlc_stream_directory_Attach( &p_stream, NULL ) != VLC_SUCCESS )
    {
        vlc_stream_Delete( p_stream );
        return vlclua_error( L );
    }
    return vlclua_stream_new_inner( L, p_stream );
}