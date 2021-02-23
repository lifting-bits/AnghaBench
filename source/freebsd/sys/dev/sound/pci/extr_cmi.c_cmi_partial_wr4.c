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
typedef  int u_int32_t ;
struct sc_info {int dummy; } ;

/* Variables and functions */
 int cmi_rd (struct sc_info*,int,int) ; 
 int /*<<< orphan*/  cmi_wr (struct sc_info*,int,int,int) ; 

__attribute__((used)) static void
cmi_partial_wr4(struct sc_info *sc,
		int reg, int shift, u_int32_t mask, u_int32_t val)
{
	u_int32_t r;

	r = cmi_rd(sc, reg, 4);
	r &= ~(mask << shift);
	r |= val << shift;
	cmi_wr(sc, reg, r, 4);
}