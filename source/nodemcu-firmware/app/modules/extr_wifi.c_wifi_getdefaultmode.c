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
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,unsigned int) ; 
 scalar_t__ wifi_get_opmode_default () ; 

__attribute__((used)) static int wifi_getdefaultmode( lua_State* L )
{
  unsigned mode;
  mode = (unsigned)wifi_get_opmode_default();
  lua_pushinteger( L, mode );
  return 1;
}