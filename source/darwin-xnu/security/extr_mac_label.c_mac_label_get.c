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
struct label {TYPE_1__* l_perpolicy; } ;
struct TYPE_2__ {scalar_t__ l_ptr; } ;

/* Variables and functions */
 int /*<<< orphan*/  KASSERT (int /*<<< orphan*/ ,char*) ; 

intptr_t
mac_label_get(struct label *l, int slot)
{
	KASSERT(l != NULL, ("mac_label_get: NULL label"));

	return ((intptr_t) (l->l_perpolicy[slot].l_ptr));
}