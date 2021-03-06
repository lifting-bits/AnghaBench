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
typedef  int /*<<< orphan*/  pg_uuid_t ;
typedef  int /*<<< orphan*/  SortSupport ;
typedef  int /*<<< orphan*/  Datum ;

/* Variables and functions */
 int /*<<< orphan*/ * DatumGetUUIDP (int /*<<< orphan*/ ) ; 
 int uuid_internal_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
uuid_fast_cmp(Datum x, Datum y, SortSupport ssup)
{
	pg_uuid_t  *arg1 = DatumGetUUIDP(x);
	pg_uuid_t  *arg2 = DatumGetUUIDP(y);

	return uuid_internal_cmp(arg1, arg2);
}