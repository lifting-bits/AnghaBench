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
typedef  int /*<<< orphan*/  DeclareCursorStmt ;

/* Variables and functions */
 int /*<<< orphan*/  COMPARE_NODE_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_SCALAR_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_STRING_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  options ; 
 int /*<<< orphan*/  portalname ; 
 int /*<<< orphan*/  query ; 

__attribute__((used)) static bool
_equalDeclareCursorStmt(const DeclareCursorStmt *a, const DeclareCursorStmt *b)
{
	COMPARE_STRING_FIELD(portalname);
	COMPARE_SCALAR_FIELD(options);
	COMPARE_NODE_FIELD(query);

	return true;
}