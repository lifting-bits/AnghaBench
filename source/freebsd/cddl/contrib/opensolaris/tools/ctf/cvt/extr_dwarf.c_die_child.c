#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  dw_err; } ;
typedef  TYPE_1__ dwarf_t ;
typedef  int /*<<< orphan*/ * Dwarf_Die ;

/* Variables and functions */
 int DW_DLV_NO_ENTRY ; 
 int DW_DLV_OK ; 
 int /*<<< orphan*/  die_off (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int dwarf_child (int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dwarf_errmsg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  terminate (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static Dwarf_Die
die_child(dwarf_t *dw, Dwarf_Die die)
{
	Dwarf_Die child;
	int rc;

	if ((rc = dwarf_child(die, &child, &dw->dw_err)) == DW_DLV_OK)
		return (child);
	else if (rc == DW_DLV_NO_ENTRY)
		return (NULL);

	terminate("die %llu: failed to find type child: %s\n",
	    die_off(dw, die), dwarf_errmsg(dw->dw_err));
	/*NOTREACHED*/
	return (NULL);
}