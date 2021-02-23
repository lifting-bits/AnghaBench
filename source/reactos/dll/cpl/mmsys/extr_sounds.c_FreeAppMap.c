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
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_6__ {struct TYPE_6__* Next; } ;
struct TYPE_5__ {TYPE_2__* pAppMap; } ;
typedef  TYPE_1__* PGLOBAL_DATA ;
typedef  TYPE_2__* PAPP_MAP ;

/* Variables and functions */
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_2__*) ; 

__attribute__((used)) static
VOID
FreeAppMap(PGLOBAL_DATA pGlobalData)
{
    PAPP_MAP pCurMap;

    while (pGlobalData->pAppMap)
    {
        pCurMap = pGlobalData->pAppMap->Next;
        HeapFree(GetProcessHeap(), 0, pGlobalData->pAppMap);
        pGlobalData->pAppMap = pCurMap;
    }
}