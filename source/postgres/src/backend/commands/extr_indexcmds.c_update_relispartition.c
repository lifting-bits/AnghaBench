#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int relispartition; } ;
struct TYPE_8__ {int /*<<< orphan*/  t_self; } ;
typedef  int /*<<< orphan*/  Relation ;
typedef  int /*<<< orphan*/  Oid ;
typedef  TYPE_1__* HeapTuple ;
typedef  TYPE_2__* Form_pg_class ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/  CatalogTupleUpdate (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  ERROR ; 
 scalar_t__ GETSTRUCT (TYPE_1__*) ; 
 int /*<<< orphan*/  HeapTupleIsValid (TYPE_1__*) ; 
 int /*<<< orphan*/  ObjectIdGetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RELOID ; 
 int /*<<< orphan*/  RelationRelationId ; 
 int /*<<< orphan*/  RowExclusiveLock ; 
 TYPE_1__* SearchSysCacheCopy1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  elog (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  heap_freetuple (TYPE_1__*) ; 
 int /*<<< orphan*/  table_close (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  table_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
update_relispartition(Oid relationId, bool newval)
{
	HeapTuple	tup;
	Relation	classRel;

	classRel = table_open(RelationRelationId, RowExclusiveLock);
	tup = SearchSysCacheCopy1(RELOID, ObjectIdGetDatum(relationId));
	if (!HeapTupleIsValid(tup))
		elog(ERROR, "cache lookup failed for relation %u", relationId);
	Assert(((Form_pg_class) GETSTRUCT(tup))->relispartition != newval);
	((Form_pg_class) GETSTRUCT(tup))->relispartition = newval;
	CatalogTupleUpdate(classRel, &tup->t_self, tup);
	heap_freetuple(tup);
	table_close(classRel, RowExclusiveLock);
}