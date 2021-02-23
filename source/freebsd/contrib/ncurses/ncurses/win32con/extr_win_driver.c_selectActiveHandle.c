#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ lastOut; } ;
struct TYPE_5__ {scalar_t__ hdl; } ;
typedef  TYPE_1__ TERMINAL_CONTROL_BLOCK ;

/* Variables and functions */
 TYPE_3__* PropOf (TYPE_1__*) ; 
 int /*<<< orphan*/  SetConsoleActiveScreenBuffer (scalar_t__) ; 

__attribute__((used)) static void
selectActiveHandle(TERMINAL_CONTROL_BLOCK * TCB)
{
    if (PropOf(TCB)->lastOut != TCB->hdl) {
	PropOf(TCB)->lastOut = TCB->hdl;
	SetConsoleActiveScreenBuffer(PropOf(TCB)->lastOut);
    }
}