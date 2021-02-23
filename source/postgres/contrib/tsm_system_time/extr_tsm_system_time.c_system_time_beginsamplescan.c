#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32 ;
struct TYPE_5__ {scalar_t__ tsm_state; } ;
struct TYPE_4__ {double millis; scalar_t__ doneblocks; int /*<<< orphan*/  lt; int /*<<< orphan*/  seed; } ;
typedef  TYPE_1__ SystemTimeSamplerData ;
typedef  TYPE_2__ SampleScanState ;
typedef  int /*<<< orphan*/  Datum ;

/* Variables and functions */
 double DatumGetFloat8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERRCODE_INVALID_TABLESAMPLE_ARGUMENT ; 
 int /*<<< orphan*/  ERROR ; 
 int /*<<< orphan*/  InvalidOffsetNumber ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errmsg (char*) ; 
 scalar_t__ isnan (double) ; 

__attribute__((used)) static void
system_time_beginsamplescan(SampleScanState *node,
							Datum *params,
							int nparams,
							uint32 seed)
{
	SystemTimeSamplerData *sampler = (SystemTimeSamplerData *) node->tsm_state;
	double		millis = DatumGetFloat8(params[0]);

	if (millis < 0 || isnan(millis))
		ereport(ERROR,
				(errcode(ERRCODE_INVALID_TABLESAMPLE_ARGUMENT),
				 errmsg("sample collection time must not be negative")));

	sampler->seed = seed;
	sampler->millis = millis;
	sampler->lt = InvalidOffsetNumber;
	sampler->doneblocks = 0;
	/* start_time, lb will be initialized during first NextSampleBlock call */
	/* we intentionally do not change nblocks/firstblock/step here */
}