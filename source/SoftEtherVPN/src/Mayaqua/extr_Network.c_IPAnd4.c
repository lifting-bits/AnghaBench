#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int UINT ;
typedef  int /*<<< orphan*/  IP ;

/* Variables and functions */
 int IPToUINT (int /*<<< orphan*/ *) ; 
 int IsIP4 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  UINTToIP (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  Zero (int /*<<< orphan*/ *,int) ; 

void IPAnd4(IP *dst, IP *a, IP *b)
{
	UINT i;
	// Validate arguments
	if (dst == NULL || a == NULL || b == NULL || IsIP4(a) == false || IsIP4(b) == false)
	{
		Zero(dst, sizeof(IP));
		return;
	}

	i = IPToUINT(a) & IPToUINT(b);

	UINTToIP(dst, i);
}