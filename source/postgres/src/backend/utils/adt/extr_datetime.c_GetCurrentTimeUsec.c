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
struct pg_tm {int dummy; } ;
typedef  int /*<<< orphan*/  fsec_t ;

/* Variables and functions */
 int /*<<< orphan*/  GetCurrentTransactionStartTimestamp () ; 
 int /*<<< orphan*/  timestamp2tm (int /*<<< orphan*/ ,int*,struct pg_tm*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void
GetCurrentTimeUsec(struct pg_tm *tm, fsec_t *fsec, int *tzp)
{
	int			tz;

	timestamp2tm(GetCurrentTransactionStartTimestamp(), &tz, tm, fsec,
				 NULL, NULL);
	/* Note: don't pass NULL tzp to timestamp2tm; affects behavior */
	if (tzp != NULL)
		*tzp = tz;
}