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
typedef  int /*<<< orphan*/  Oid ;

/* Variables and functions */
 int /*<<< orphan*/  ERRCODE_INVALID_TABLE_DEFINITION ; 
 int /*<<< orphan*/  ERROR ; 
 int LocalTableEmpty (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errdetail (char*,char*) ; 
 int /*<<< orphan*/  errhint (char*) ; 
 int /*<<< orphan*/  errmsg (char*,char*) ; 
 char* get_rel_name (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
EnsureLocalTableEmpty(Oid relationId)
{
	char *relationName = get_rel_name(relationId);
	bool localTableEmpty = LocalTableEmpty(relationId);

	if (!localTableEmpty)
	{
		ereport(ERROR, (errcode(ERRCODE_INVALID_TABLE_DEFINITION),
						errmsg("cannot distribute relation \"%s\"", relationName),
						errdetail("Relation \"%s\" contains data.", relationName),
						errhint("Empty your table before distributing it.")));
	}
}