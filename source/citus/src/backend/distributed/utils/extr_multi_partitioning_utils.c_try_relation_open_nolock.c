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
typedef  int /*<<< orphan*/ * Relation ;
typedef  int /*<<< orphan*/  Oid ;

/* Variables and functions */
 int /*<<< orphan*/  ObjectIdGetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RELOID ; 
 int /*<<< orphan*/ * RelationIdGetRelation (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RelationIsValid (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SearchSysCacheExists1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pgstat_initstats (int /*<<< orphan*/ *) ; 

__attribute__((used)) static Relation
try_relation_open_nolock(Oid relationId)
{
	Relation relation = NULL;
	if (!SearchSysCacheExists1(RELOID, ObjectIdGetDatum(relationId)))
	{
		return NULL;
	}

	relation = RelationIdGetRelation(relationId);
	if (!RelationIsValid(relation))
	{
		return NULL;
	}

	pgstat_initstats(relation);

	return relation;
}