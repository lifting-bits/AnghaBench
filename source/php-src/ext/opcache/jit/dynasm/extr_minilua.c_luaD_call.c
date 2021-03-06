#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int nCcalls; } ;
typedef  TYPE_1__ lua_State ;
typedef  int /*<<< orphan*/  StkId ;

/* Variables and functions */
 int /*<<< orphan*/  luaC_checkGC (TYPE_1__*) ; 
 scalar_t__ luaD_precall (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  luaD_throw (TYPE_1__*,int) ; 
 int /*<<< orphan*/  luaG_runerror (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  luaV_execute (TYPE_1__*,int) ; 

__attribute__((used)) static void luaD_call(lua_State*L,StkId func,int nResults){
if(++L->nCcalls>=200){
if(L->nCcalls==200)
luaG_runerror(L,"C stack overflow");
else if(L->nCcalls>=(200+(200>>3)))
luaD_throw(L,5);
}
if(luaD_precall(L,func,nResults)==0)
luaV_execute(L,1);
L->nCcalls--;
luaC_checkGC(L);
}