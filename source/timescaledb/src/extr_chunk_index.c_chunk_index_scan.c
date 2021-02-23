#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tuple_found_func ;
typedef  int /*<<< orphan*/  tuple_filter_func ;
struct TYPE_3__ {int nkeys; void* data; int /*<<< orphan*/  scandirection; int /*<<< orphan*/  lockmode; int /*<<< orphan*/  filter; int /*<<< orphan*/  tuple_found; int /*<<< orphan*/ * scankey; int /*<<< orphan*/  index; int /*<<< orphan*/  table; } ;
typedef  TYPE_1__ ScannerCtx ;
typedef  int /*<<< orphan*/  ScanKeyData ;
typedef  int /*<<< orphan*/  LOCKMODE ;
typedef  int /*<<< orphan*/  Catalog ;

/* Variables and functions */
 int /*<<< orphan*/  CHUNK_INDEX ; 
 int /*<<< orphan*/  ForwardScanDirection ; 
 int /*<<< orphan*/  catalog_get_index (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  catalog_get_table_id (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ts_catalog_get () ; 
 int ts_scanner_scan (TYPE_1__*) ; 

__attribute__((used)) static int
chunk_index_scan(int indexid, ScanKeyData scankey[], int nkeys, tuple_found_func tuple_found,
				 tuple_filter_func tuple_filter, void *data, LOCKMODE lockmode)
{
	Catalog *catalog = ts_catalog_get();
	ScannerCtx scanCtx = {
		.table = catalog_get_table_id(catalog, CHUNK_INDEX),
		.index = catalog_get_index(catalog, CHUNK_INDEX, indexid),
		.nkeys = nkeys,
		.scankey = scankey,
		.tuple_found = tuple_found,
		.filter = tuple_filter,
		.data = data,
		.lockmode = lockmode,
		.scandirection = ForwardScanDirection,
	};

	return ts_scanner_scan(&scanCtx);
}