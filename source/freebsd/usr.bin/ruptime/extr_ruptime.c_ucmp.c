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
struct TYPE_3__ {int hs_nusers; } ;

/* Variables and functions */
 TYPE_1__* HS (void const*) ; 
 scalar_t__ ISDOWN (TYPE_1__*) ; 
 int rflg ; 
 int tcmp (void const*,void const*) ; 

__attribute__((used)) static int
ucmp(const void *a1, const void *a2)
{
	if (ISDOWN(HS(a1)))
		if (ISDOWN(HS(a2)))
			return (tcmp(a1, a2));
		else
			return (rflg);
	else if (ISDOWN(HS(a2)))
		return (-rflg);
	else
		return (rflg * (HS(a2)->hs_nusers - HS(a1)->hs_nusers));
}