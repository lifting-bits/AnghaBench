#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_4__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ i; } ;
struct TYPE_5__ {int /*<<< orphan*/  pStack; } ;
typedef  TYPE_1__ FICL_VM ;
typedef  scalar_t__ FICL_INT ;

/* Variables and functions */
 int /*<<< orphan*/  LVALUEtoCELL (scalar_t__) ; 
 TYPE_4__ stackGetTop (int /*<<< orphan*/ ) ; 
 scalar_t__ stackPopINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stackSetTop (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vmCheckStack (TYPE_1__*,int,int) ; 

__attribute__((used)) static void sub(FICL_VM *pVM)
{
    FICL_INT i;
#if FICL_ROBUST > 1
    vmCheckStack(pVM, 2, 1);
#endif
    i = stackPopINT(pVM->pStack);
    i = stackGetTop(pVM->pStack).i - i;
    stackSetTop(pVM->pStack, LVALUEtoCELL(i));
    return;
}