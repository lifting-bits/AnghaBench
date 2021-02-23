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
struct TYPE_5__ {struct TYPE_5__* p_TgecDriverParam; } ;
typedef  TYPE_1__ t_Tgec ;
typedef  scalar_t__ t_Handle ;
typedef  int /*<<< orphan*/  t_Error ;

/* Variables and functions */
 int /*<<< orphan*/  E_INVALID_HANDLE ; 
 int /*<<< orphan*/  E_OK ; 
 int /*<<< orphan*/  FreeInitResources (TYPE_1__*) ; 
 int /*<<< orphan*/  SANITY_CHECK_RETURN_ERROR (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XX_Free (TYPE_1__*) ; 

__attribute__((used)) static t_Error TgecFree(t_Handle h_Tgec)
{
    t_Tgec       *p_Tgec = (t_Tgec *)h_Tgec;

    SANITY_CHECK_RETURN_ERROR(p_Tgec, E_INVALID_HANDLE);

    if (p_Tgec->p_TgecDriverParam)
    {
        /* Called after config */
        XX_Free(p_Tgec->p_TgecDriverParam);
        p_Tgec->p_TgecDriverParam = NULL;
    }
    else
        /* Called after init */
        FreeInitResources(p_Tgec);

    XX_Free(p_Tgec);

    return E_OK;
}