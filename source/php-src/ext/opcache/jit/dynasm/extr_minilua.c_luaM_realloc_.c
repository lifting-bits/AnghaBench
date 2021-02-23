#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_3__ {size_t totalbytes; int /*<<< orphan*/  ud; void* (* frealloc ) (int /*<<< orphan*/ ,void*,size_t,size_t) ;} ;
typedef  TYPE_1__ global_State ;

/* Variables and functions */
 TYPE_1__* G (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaD_throw (int /*<<< orphan*/ *,int) ; 
 void* stub1 (int /*<<< orphan*/ ,void*,size_t,size_t) ; 

__attribute__((used)) static void*luaM_realloc_(lua_State*L,void*block,size_t osize,size_t nsize){
global_State*g=G(L);
block=(*g->frealloc)(g->ud,block,osize,nsize);
if(block==NULL&&nsize>0)
luaD_throw(L,4);
g->totalbytes=(g->totalbytes-osize)+nsize;
return block;
}