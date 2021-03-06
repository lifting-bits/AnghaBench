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
typedef  int /*<<< orphan*/  TString ;

/* Variables and functions */
 int /*<<< orphan*/ * luaS_newlstr (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

TString *luaS_new (lua_State *L, const char *str) {
  return luaS_newlstr(L, str, strlen(str));
}