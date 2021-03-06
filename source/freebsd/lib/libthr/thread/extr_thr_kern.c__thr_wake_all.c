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

/* Variables and functions */
 int /*<<< orphan*/  UMTX_OP_NWAKE_PRIVATE ; 
 int /*<<< orphan*/  _umtx_op (unsigned int**,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void
_thr_wake_all(unsigned int *waddrs[], int count)
{
	int i;

	for (i = 0; i < count; ++i)
		*waddrs[i] = 1;
	_umtx_op(waddrs, UMTX_OP_NWAKE_PRIVATE, count, NULL, NULL);
}