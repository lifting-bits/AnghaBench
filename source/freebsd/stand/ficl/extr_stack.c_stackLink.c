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
struct TYPE_4__ {int pFrame; int sp; } ;
typedef  TYPE_1__ FICL_STACK ;

/* Variables and functions */
 int /*<<< orphan*/  stackPushPtr (TYPE_1__*,int) ; 

void stackLink(FICL_STACK *pStack, int nCells)
{
    stackPushPtr(pStack, pStack->pFrame);
    pStack->pFrame = pStack->sp;
    pStack->sp += nCells;
    return;
}