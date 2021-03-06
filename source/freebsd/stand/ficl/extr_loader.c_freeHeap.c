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
struct TYPE_3__ {int /*<<< orphan*/  pSys; int /*<<< orphan*/  pStack; } ;
typedef  TYPE_1__ FICL_VM ;

/* Variables and functions */
 int /*<<< orphan*/  dictCellsAvail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ficlGetDict (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stackPushINT (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void freeHeap(FICL_VM *pVM)
{
    stackPushINT(pVM->pStack, dictCellsAvail(ficlGetDict(pVM->pSys)));
}