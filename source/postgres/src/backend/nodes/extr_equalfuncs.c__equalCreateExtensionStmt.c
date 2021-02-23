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
typedef  int /*<<< orphan*/  CreateExtensionStmt ;

/* Variables and functions */
 int /*<<< orphan*/  COMPARE_NODE_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_SCALAR_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_STRING_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  extname ; 
 int /*<<< orphan*/  if_not_exists ; 
 int /*<<< orphan*/  options ; 

__attribute__((used)) static bool
_equalCreateExtensionStmt(const CreateExtensionStmt *a, const CreateExtensionStmt *b)
{
	COMPARE_STRING_FIELD(extname);
	COMPARE_SCALAR_FIELD(if_not_exists);
	COMPARE_NODE_FIELD(options);

	return true;
}