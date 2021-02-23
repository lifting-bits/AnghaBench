#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int objectType; } ;
typedef  int /*<<< orphan*/  List ;
typedef  TYPE_1__ AlterOwnerStmt ;

/* Variables and functions */
 int /*<<< orphan*/ * NIL ; 
#define  OBJECT_AGGREGATE 131 
#define  OBJECT_FUNCTION 130 
#define  OBJECT_PROCEDURE 129 
#define  OBJECT_TYPE 128 
 int /*<<< orphan*/ * PlanAlterFunctionOwnerStmt (TYPE_1__*,char const*) ; 
 int /*<<< orphan*/ * PlanAlterTypeOwnerStmt (TYPE_1__*,char const*) ; 

__attribute__((used)) static List *
PlanAlterOwnerStmt(AlterOwnerStmt *stmt, const char *queryString)
{
	switch (stmt->objectType)
	{
		case OBJECT_TYPE:
		{
			return PlanAlterTypeOwnerStmt(stmt, queryString);
		}

		case OBJECT_PROCEDURE:
		case OBJECT_AGGREGATE:
		case OBJECT_FUNCTION:
		{
			return PlanAlterFunctionOwnerStmt(stmt, queryString);
		}

		default:
		{
			/* do nothing for unsupported alter owner statements */
			return NIL;
		}
	}
}