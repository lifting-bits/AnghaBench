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
typedef  int /*<<< orphan*/  DropRoleStmt ;

/* Variables and functions */
 int /*<<< orphan*/  COMPARE_NODE_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_SCALAR_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  missing_ok ; 
 int /*<<< orphan*/  roles ; 

__attribute__((used)) static bool
_equalDropRoleStmt(const DropRoleStmt *a, const DropRoleStmt *b)
{
	COMPARE_NODE_FIELD(roles);
	COMPARE_SCALAR_FIELD(missing_ok);

	return true;
}