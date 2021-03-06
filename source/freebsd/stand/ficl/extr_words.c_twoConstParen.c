#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  pStack; TYPE_1__* runningWord; } ;
struct TYPE_5__ {int /*<<< orphan*/ * param; } ;
typedef  TYPE_1__ FICL_WORD ;
typedef  TYPE_2__ FICL_VM ;

/* Variables and functions */
 int /*<<< orphan*/  stackPush (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vmCheckStack (TYPE_2__*,int /*<<< orphan*/ ,int) ; 

void twoConstParen(FICL_VM *pVM)
{
    FICL_WORD *pFW = pVM->runningWord;
#if FICL_ROBUST > 1
    vmCheckStack(pVM, 0, 2);
#endif
    stackPush(pVM->pStack, pFW->param[0]); /* lo */
    stackPush(pVM->pStack, pFW->param[1]); /* hi */
    return;
}