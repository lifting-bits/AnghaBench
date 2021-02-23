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
struct dmar_unit {int dummy; } ;
typedef  int /*<<< orphan*/  dmar_root_entry_t ;

/* Variables and functions */
 int /*<<< orphan*/  dmar_flush_transl_to_ram (struct dmar_unit*,int /*<<< orphan*/ *,int) ; 

void
dmar_flush_root_to_ram(struct dmar_unit *unit, dmar_root_entry_t *dst)
{

	dmar_flush_transl_to_ram(unit, dst, sizeof(*dst));
}