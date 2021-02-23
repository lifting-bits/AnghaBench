#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  amname; } ;
struct TYPE_3__ {int /*<<< orphan*/  opfname; int /*<<< orphan*/  opfnamespace; int /*<<< orphan*/  opfmethod; } ;
typedef  int /*<<< orphan*/  StringInfo ;
typedef  int /*<<< orphan*/  Oid ;
typedef  int /*<<< orphan*/  List ;
typedef  int /*<<< orphan*/  HeapTuple ;
typedef  TYPE_1__* Form_pg_opfamily ;
typedef  TYPE_2__* Form_pg_am ;

/* Variables and functions */
 int /*<<< orphan*/  AMOID ; 
 int /*<<< orphan*/  ERROR ; 
 scalar_t__ GETSTRUCT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HeapTupleIsValid (int /*<<< orphan*/ ) ; 
 char* NameStr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OPFAMILYOID ; 
 int /*<<< orphan*/  ObjectIdGetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseSysCache (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SearchSysCache1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  appendStringInfo (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  elog (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 char* get_namespace_name_or_temp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * list_make3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pstrdup (char*) ; 
 int /*<<< orphan*/  quote_qualified_identifier (char*,char*) ; 

__attribute__((used)) static void
getOpFamilyIdentity(StringInfo buffer, Oid opfid, List **object)
{
	HeapTuple	opfTup;
	Form_pg_opfamily opfForm;
	HeapTuple	amTup;
	Form_pg_am	amForm;
	char	   *schema;

	opfTup = SearchSysCache1(OPFAMILYOID, ObjectIdGetDatum(opfid));
	if (!HeapTupleIsValid(opfTup))
		elog(ERROR, "cache lookup failed for opfamily %u", opfid);
	opfForm = (Form_pg_opfamily) GETSTRUCT(opfTup);

	amTup = SearchSysCache1(AMOID, ObjectIdGetDatum(opfForm->opfmethod));
	if (!HeapTupleIsValid(amTup))
		elog(ERROR, "cache lookup failed for access method %u",
			 opfForm->opfmethod);
	amForm = (Form_pg_am) GETSTRUCT(amTup);

	schema = get_namespace_name_or_temp(opfForm->opfnamespace);
	appendStringInfo(buffer, "%s USING %s",
					 quote_qualified_identifier(schema,
												NameStr(opfForm->opfname)),
					 NameStr(amForm->amname));

	if (object)
		*object = list_make3(pstrdup(NameStr(amForm->amname)),
							 pstrdup(schema),
							 pstrdup(NameStr(opfForm->opfname)));

	ReleaseSysCache(amTup);
	ReleaseSysCache(opfTup);
}