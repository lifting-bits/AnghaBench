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
typedef  int /*<<< orphan*/  MVNDistinct ;
typedef  int /*<<< orphan*/  HeapTuple ;
typedef  int /*<<< orphan*/  Datum ;

/* Variables and functions */
 int /*<<< orphan*/  Anum_pg_statistic_ext_data_stxdndistinct ; 
 int /*<<< orphan*/  DatumGetByteaPP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERROR ; 
 int /*<<< orphan*/  HeapTupleIsValid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ObjectIdGetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseSysCache (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STATEXTDATASTXOID ; 
 int /*<<< orphan*/  STATS_EXT_NDISTINCT ; 
 int /*<<< orphan*/  SearchSysCache1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SysCacheGetAttr (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  elog (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/ * statext_ndistinct_deserialize (int /*<<< orphan*/ ) ; 

MVNDistinct *
statext_ndistinct_load(Oid mvoid)
{
	MVNDistinct *result;
	bool		isnull;
	Datum		ndist;
	HeapTuple	htup;

	htup = SearchSysCache1(STATEXTDATASTXOID, ObjectIdGetDatum(mvoid));
	if (!HeapTupleIsValid(htup))
		elog(ERROR, "cache lookup failed for statistics object %u", mvoid);

	ndist = SysCacheGetAttr(STATEXTDATASTXOID, htup,
							Anum_pg_statistic_ext_data_stxdndistinct, &isnull);
	if (isnull)
		elog(ERROR,
			 "requested statistic kind \"%c\" is not yet built for statistics object %u",
			 STATS_EXT_NDISTINCT, mvoid);

	result = statext_ndistinct_deserialize(DatumGetByteaPP(ndist));

	ReleaseSysCache(htup);

	return result;
}