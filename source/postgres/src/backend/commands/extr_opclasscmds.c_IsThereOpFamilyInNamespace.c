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
 int /*<<< orphan*/  CStringGetDatum (char const*) ; 
 int /*<<< orphan*/  ERRCODE_DUPLICATE_OBJECT ; 
 int /*<<< orphan*/  ERROR ; 
 int /*<<< orphan*/  OPFAMILYAMNAMENSP ; 
 int /*<<< orphan*/  ObjectIdGetDatum (int /*<<< orphan*/ ) ; 
 scalar_t__ SearchSysCacheExists3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errmsg (char*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_am_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_namespace_name (int /*<<< orphan*/ ) ; 

void
IsThereOpFamilyInNamespace(const char *opfname, Oid opfmethod,
						   Oid opfnamespace)
{
	/* make sure the new name doesn't exist */
	if (SearchSysCacheExists3(OPFAMILYAMNAMENSP,
							  ObjectIdGetDatum(opfmethod),
							  CStringGetDatum(opfname),
							  ObjectIdGetDatum(opfnamespace)))
		ereport(ERROR,
				(errcode(ERRCODE_DUPLICATE_OBJECT),
				 errmsg("operator family \"%s\" for access method \"%s\" already exists in schema \"%s\"",
						opfname,
						get_am_name(opfmethod),
						get_namespace_name(opfnamespace))));
}