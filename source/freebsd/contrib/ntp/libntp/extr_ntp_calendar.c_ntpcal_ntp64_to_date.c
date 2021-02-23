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
typedef  int /*<<< orphan*/  vint64 ;
struct calendar {int dummy; } ;
struct TYPE_3__ {scalar_t__ hi; int /*<<< orphan*/  lo; } ;
typedef  TYPE_1__ ntpcal_split ;

/* Variables and functions */
 scalar_t__ DAY_NTP_STARTS ; 
 scalar_t__ ntpcal_daysec_to_date (struct calendar*,int /*<<< orphan*/ ) ; 
 TYPE_1__ ntpcal_daysplit (int /*<<< orphan*/  const*) ; 
 int ntpcal_rd_to_date (struct calendar*,scalar_t__) ; 

int
ntpcal_ntp64_to_date(
	struct calendar *jd,
	const vint64    *ntp
	)
{
	ntpcal_split ds;

	ds = ntpcal_daysplit(ntp);
	ds.hi += ntpcal_daysec_to_date(jd, ds.lo);

	return ntpcal_rd_to_date(jd, ds.hi + DAY_NTP_STARTS);
}