#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int pc; } ;
typedef  TYPE_1__ FuncState ;

/* Variables and functions */
 int /*<<< orphan*/  luaK_patchtohere (TYPE_1__*,int) ; 
 int /*<<< orphan*/  patchlistaux (TYPE_1__*,int,int,int,int) ; 

__attribute__((used)) static void luaK_patchlist(FuncState*fs,int list,int target){
if(target==fs->pc)
luaK_patchtohere(fs,list);
else{
patchlistaux(fs,list,target,((1<<8)-1),target);
}
}