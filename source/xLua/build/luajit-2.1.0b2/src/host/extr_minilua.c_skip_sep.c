#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int current; } ;
typedef  TYPE_1__ LexState ;

/* Variables and functions */
 int /*<<< orphan*/  save_and_next (TYPE_1__*) ; 

__attribute__((used)) static int skip_sep(LexState*ls){
int count=0;
int s=ls->current;
save_and_next(ls);
while(ls->current=='='){
save_and_next(ls);
count++;
}
return(ls->current==s)?count:(-count)-1;
}