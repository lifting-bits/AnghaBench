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
typedef  size_t u8 ;
struct gf128mul_4k {int /*<<< orphan*/ * t; } ;
typedef  int /*<<< orphan*/  be128 ;

/* Variables and functions */
 int /*<<< orphan*/  be128_xor (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gf128mul_x8_bbe (int /*<<< orphan*/ *) ; 

void gf128mul_4k_bbe(be128 *a, struct gf128mul_4k *t)
{
	u8 *ap = (u8 *)a;
	be128 r[1];
	int i = 0;

	*r = t->t[ap[0]];
	while (++i < 16) {
		gf128mul_x8_bbe(r);
		be128_xor(r, r, &t->t[ap[i]]);
	}
	*a = *r;
}