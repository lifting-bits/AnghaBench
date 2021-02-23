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
typedef  int /*<<< orphan*/  TValue ;
typedef  int /*<<< orphan*/  TMS ;
typedef  int /*<<< orphan*/  StkId ;

/* Variables and functions */
 int /*<<< orphan*/  callTMres (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * luaT_gettmbyobj (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 scalar_t__ ttisnil (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static int call_binTM(lua_State*L,const TValue*p1,const TValue*p2,
StkId res,TMS event){
const TValue*tm=luaT_gettmbyobj(L,p1,event);
if(ttisnil(tm))
tm=luaT_gettmbyobj(L,p2,event);
if(ttisnil(tm))return 0;
callTMres(L,res,tm,p1,p2);
return 1;
}