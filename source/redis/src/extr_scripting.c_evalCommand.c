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
struct TYPE_5__ {int flags; } ;
typedef  TYPE_1__ client ;

/* Variables and functions */
 int CLIENT_LUA_DEBUG ; 
 int /*<<< orphan*/  evalGenericCommand (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  evalGenericCommandWithDebugging (TYPE_1__*,int /*<<< orphan*/ ) ; 

void evalCommand(client *c) {
    if (!(c->flags & CLIENT_LUA_DEBUG))
        evalGenericCommand(c,0);
    else
        evalGenericCommandWithDebugging(c,0);
}