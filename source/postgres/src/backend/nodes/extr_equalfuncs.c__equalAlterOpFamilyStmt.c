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
typedef  int /*<<< orphan*/  AlterOpFamilyStmt ;

/* Variables and functions */
 int /*<<< orphan*/  COMPARE_NODE_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_SCALAR_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_STRING_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  amname ; 
 int /*<<< orphan*/  isDrop ; 
 int /*<<< orphan*/  items ; 
 int /*<<< orphan*/  opfamilyname ; 

__attribute__((used)) static bool
_equalAlterOpFamilyStmt(const AlterOpFamilyStmt *a, const AlterOpFamilyStmt *b)
{
	COMPARE_NODE_FIELD(opfamilyname);
	COMPARE_STRING_FIELD(amname);
	COMPARE_SCALAR_FIELD(isDrop);
	COMPARE_NODE_FIELD(items);

	return true;
}