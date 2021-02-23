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
typedef  int /*<<< orphan*/  CreatePolicyStmt ;

/* Variables and functions */
 int /*<<< orphan*/  COMPARE_NODE_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_SCALAR_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_STRING_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cmd_name ; 
 int /*<<< orphan*/  permissive ; 
 int /*<<< orphan*/  policy_name ; 
 int /*<<< orphan*/  qual ; 
 int /*<<< orphan*/  roles ; 
 int /*<<< orphan*/  table ; 
 int /*<<< orphan*/  with_check ; 

__attribute__((used)) static bool
_equalCreatePolicyStmt(const CreatePolicyStmt *a, const CreatePolicyStmt *b)
{
	COMPARE_STRING_FIELD(policy_name);
	COMPARE_NODE_FIELD(table);
	COMPARE_STRING_FIELD(cmd_name);
	COMPARE_SCALAR_FIELD(permissive);
	COMPARE_NODE_FIELD(roles);
	COMPARE_NODE_FIELD(qual);
	COMPARE_NODE_FIELD(with_check);

	return true;
}