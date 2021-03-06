#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  int64 ;
struct TYPE_6__ {int /*<<< orphan*/  typlen; int /*<<< orphan*/  typbyval; } ;
struct TYPE_5__ {int isnull; int /*<<< orphan*/  value; int /*<<< orphan*/  time; } ;
struct TYPE_7__ {TYPE_2__ base; TYPE_1__ next; } ;
typedef  TYPE_3__ GapFillInterpolateColumnState ;
typedef  int /*<<< orphan*/  Datum ;

/* Variables and functions */
 int /*<<< orphan*/  datumCopy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
gapfill_interpolate_tuple_fetched(GapFillInterpolateColumnState *column, int64 time, Datum value,
								  bool isnull)
{
	column->next.isnull = isnull;
	if (!isnull)
	{
		column->next.time = time;
		column->next.value = datumCopy(value, column->base.typbyval, column->base.typlen);
	}
}