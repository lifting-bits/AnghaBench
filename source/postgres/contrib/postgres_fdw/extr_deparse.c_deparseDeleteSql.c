#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {TYPE_1__* trigdesc; } ;
struct TYPE_6__ {scalar_t__ trig_delete_after_row; } ;
typedef  int /*<<< orphan*/  StringInfo ;
typedef  TYPE_2__* Relation ;
typedef  int /*<<< orphan*/  RangeTblEntry ;
typedef  int /*<<< orphan*/  List ;
typedef  int /*<<< orphan*/  Index ;

/* Variables and functions */
 int /*<<< orphan*/  NIL ; 
 int /*<<< orphan*/  appendStringInfoString (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  deparseRelation (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  deparseReturningList (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_2__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 

void
deparseDeleteSql(StringInfo buf, RangeTblEntry *rte,
				 Index rtindex, Relation rel,
				 List *returningList,
				 List **retrieved_attrs)
{
	appendStringInfoString(buf, "DELETE FROM ");
	deparseRelation(buf, rel);
	appendStringInfoString(buf, " WHERE ctid = $1");

	deparseReturningList(buf, rte, rtindex, rel,
						 rel->trigdesc && rel->trigdesc->trig_delete_after_row,
						 NIL, returningList, retrieved_attrs);
}