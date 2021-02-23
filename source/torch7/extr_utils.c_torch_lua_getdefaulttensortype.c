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
 int /*<<< orphan*/  lua_pushstring (int /*<<< orphan*/ *,char const*) ; 
 char* torch_getdefaulttensortype (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int torch_lua_getdefaulttensortype(lua_State *L)
{
  const char* tname = torch_getdefaulttensortype(L);
  if(tname)
  {
    lua_pushstring(L, tname);
    return 1;
  }
  return 0;
}