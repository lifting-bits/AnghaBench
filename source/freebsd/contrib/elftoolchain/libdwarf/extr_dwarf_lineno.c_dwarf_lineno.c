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
struct TYPE_3__ {int /*<<< orphan*/  ln_lineno; } ;
typedef  int /*<<< orphan*/  Dwarf_Unsigned ;
typedef  TYPE_1__* Dwarf_Line ;
typedef  int /*<<< orphan*/  Dwarf_Error ;

/* Variables and functions */
 int /*<<< orphan*/  DWARF_SET_ERROR (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DW_DLE_ARGUMENT ; 
 int DW_DLV_ERROR ; 
 int DW_DLV_OK ; 

int
dwarf_lineno(Dwarf_Line ln, Dwarf_Unsigned *ret_lineno, Dwarf_Error *error)
{

	if (ln == NULL || ret_lineno == NULL) {
		DWARF_SET_ERROR(NULL, error, DW_DLE_ARGUMENT);
		return (DW_DLV_ERROR);
	}

	*ret_lineno = ln->ln_lineno;

	return (DW_DLV_OK);
}