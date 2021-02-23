#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int freereg; TYPE_1__* f; int /*<<< orphan*/  ls; } ;
struct TYPE_4__ {int maxstacksize; } ;
typedef  TYPE_2__ FuncState ;

/* Variables and functions */
 int cast_byte (int) ; 
 int /*<<< orphan*/  luaX_syntaxerror (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void luaK_checkstack(FuncState*fs,int n){
int newstack=fs->freereg+n;
if(newstack>fs->f->maxstacksize){
if(newstack>=250)
luaX_syntaxerror(fs->ls,"function or expression too complex");
fs->f->maxstacksize=cast_byte(newstack);
}
}