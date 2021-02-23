#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/  info; } ;
struct TYPE_10__ {TYPE_1__ s; } ;
struct TYPE_11__ {int k; int f; int t; TYPE_2__ u; } ;
typedef  TYPE_3__ expdesc ;
typedef  int /*<<< orphan*/  FuncState ;

/* Variables and functions */
 int /*<<< orphan*/  OP_NOT ; 
#define  VFALSE 135 
#define  VJMP 134 
#define  VK 133 
#define  VKNUM 132 
#define  VNIL 131 
#define  VNONRELOC 130 
#define  VRELOCABLE 129 
#define  VTRUE 128 
 int /*<<< orphan*/  discharge2anyreg (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  freeexp (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  invertjump (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  luaK_codeABC (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  luaK_dischargevars (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  removevalues (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void codenot(FuncState*fs,expdesc*e){
luaK_dischargevars(fs,e);
switch(e->k){
case VNIL:case VFALSE:{
e->k=VTRUE;
break;
}
case VK:case VKNUM:case VTRUE:{
e->k=VFALSE;
break;
}
case VJMP:{
invertjump(fs,e);
break;
}
case VRELOCABLE:
case VNONRELOC:{
discharge2anyreg(fs,e);
freeexp(fs,e);
e->u.s.info=luaK_codeABC(fs,OP_NOT,0,e->u.s.info,0);
e->k=VRELOCABLE;
break;
}
default:{
break;
}
}
{int temp=e->f;e->f=e->t;e->t=temp;}
removevalues(fs,e->f);
removevalues(fs,e->t);
}