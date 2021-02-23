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
typedef  int /*<<< orphan*/  CT ;

/* Variables and functions */
 int /*<<< orphan*/  CtInsertColumn (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * CtNew () ; 
 int /*<<< orphan*/  _UU (char*) ; 

CT *CtNewStandardEx()
{
	CT *ct = CtNew();

	CtInsertColumn(ct, _UU("CMD_CT_STD_COLUMN_1"), false);
	CtInsertColumn(ct, _UU("CMD_CT_STD_COLUMN_2"), false);
	CtInsertColumn(ct, _UU("CMD_CT_STD_COLUMN_3"), false);

	return ct;
}