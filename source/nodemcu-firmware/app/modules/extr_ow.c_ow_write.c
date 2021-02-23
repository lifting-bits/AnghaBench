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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  MOD_CHECK_ID (int /*<<< orphan*/ ,unsigned int) ; 
 unsigned int luaL_checkinteger (int /*<<< orphan*/ *,int) ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ lua_isnumber (int /*<<< orphan*/ *,int) ; 
 int lua_tointeger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  onewire_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ow ; 

__attribute__((used)) static int ow_write( lua_State *L )
{
  int power = 0;
  unsigned id = luaL_checkinteger( L, 1 );
  MOD_CHECK_ID( ow, id );

  int v = (int)luaL_checkinteger( L, 2 );
  if( v > 255 )
    return luaL_error( L, "wrong arg range" );
  if(lua_isnumber(L, 3))
    power = lua_tointeger(L, 3);
  if(power!=0)
    power = 1;

  onewire_write((uint8_t)id, (uint8_t)v, (uint8_t)power);

  return 0;
}