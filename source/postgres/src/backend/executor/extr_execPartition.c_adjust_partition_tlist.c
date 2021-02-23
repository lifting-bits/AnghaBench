#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  int32 ;
typedef  TYPE_1__* TupleDesc ;
struct TYPE_11__ {int* attrMap; TYPE_1__* outdesc; } ;
typedef  TYPE_2__ TupleConversionMap ;
struct TYPE_12__ {int resno; } ;
typedef  TYPE_3__ TargetEntry ;
struct TYPE_13__ {int attisdropped; int /*<<< orphan*/  attname; } ;
struct TYPE_10__ {int natts; } ;
typedef  int /*<<< orphan*/  List ;
typedef  TYPE_4__* Form_pg_attribute ;
typedef  int /*<<< orphan*/  Expr ;
typedef  int /*<<< orphan*/  Datum ;
typedef  int /*<<< orphan*/  Const ;
typedef  int AttrNumber ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/  INT4OID ; 
 int InvalidAttrNumber ; 
 int /*<<< orphan*/  InvalidOid ; 
 int /*<<< orphan*/ * NIL ; 
 int /*<<< orphan*/  NameStr (int /*<<< orphan*/ ) ; 
 TYPE_4__* TupleDescAttr (TYPE_1__*,int) ; 
 int /*<<< orphan*/ * lappend (int /*<<< orphan*/ *,TYPE_3__*) ; 
 scalar_t__ list_nth (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * makeConst (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int) ; 
 TYPE_3__* makeTargetEntry (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pstrdup (int /*<<< orphan*/ ) ; 

__attribute__((used)) static List *
adjust_partition_tlist(List *tlist, TupleConversionMap *map)
{
	List	   *new_tlist = NIL;
	TupleDesc	tupdesc = map->outdesc;
	AttrNumber *attrMap = map->attrMap;
	AttrNumber	attrno;

	for (attrno = 1; attrno <= tupdesc->natts; attrno++)
	{
		Form_pg_attribute att_tup = TupleDescAttr(tupdesc, attrno - 1);
		TargetEntry *tle;

		if (attrMap[attrno - 1] != InvalidAttrNumber)
		{
			Assert(!att_tup->attisdropped);

			/*
			 * Use the corresponding entry from the parent's tlist, adjusting
			 * the resno the match the partition's attno.
			 */
			tle = (TargetEntry *) list_nth(tlist, attrMap[attrno - 1] - 1);
			tle->resno = attrno;
		}
		else
		{
			Const	   *expr;

			/*
			 * For a dropped attribute in the partition, generate a dummy
			 * entry with resno matching the partition's attno.
			 */
			Assert(att_tup->attisdropped);
			expr = makeConst(INT4OID,
							 -1,
							 InvalidOid,
							 sizeof(int32),
							 (Datum) 0,
							 true,	/* isnull */
							 true /* byval */ );
			tle = makeTargetEntry((Expr *) expr,
								  attrno,
								  pstrdup(NameStr(att_tup->attname)),
								  false);
		}

		new_tlist = lappend(new_tlist, tle);
	}

	return new_tlist;
}