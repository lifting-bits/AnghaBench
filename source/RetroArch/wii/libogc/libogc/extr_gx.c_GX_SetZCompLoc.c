#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_2__ {int peCntrl; } ;

/* Variables and functions */
 int /*<<< orphan*/  GX_LOAD_BP_REG (int) ; 
 int _SHIFTL (int /*<<< orphan*/ ,int,int) ; 
 TYPE_1__* __gx ; 

void GX_SetZCompLoc(u8 before_tex)
{
	__gx->peCntrl = (__gx->peCntrl&~0x40)|(_SHIFTL(before_tex,6,1));
	GX_LOAD_BP_REG(__gx->peCntrl);
}