#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int typlen; int /*<<< orphan*/  typelem; } ;
typedef  int /*<<< orphan*/  Oid ;
typedef  int /*<<< orphan*/  HeapTuple ;
typedef  TYPE_1__* Form_pg_type ;

/* Variables and functions */
 int /*<<< orphan*/  GETSTRUCT (int /*<<< orphan*/ ) ; 
 scalar_t__ HeapTupleIsValid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InvalidOid ; 
 int /*<<< orphan*/  ObjectIdGetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseSysCache (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SearchSysCache1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TYPEOID ; 

Oid
get_element_type(Oid typid)
{
	HeapTuple	tp;

	tp = SearchSysCache1(TYPEOID, ObjectIdGetDatum(typid));
	if (HeapTupleIsValid(tp))
	{
		Form_pg_type typtup = (Form_pg_type) GETSTRUCT(tp);
		Oid			result;

		if (typtup->typlen == -1)
			result = typtup->typelem;
		else
			result = InvalidOid;
		ReleaseSysCache(tp);
		return result;
	}
	else
		return InvalidOid;
}