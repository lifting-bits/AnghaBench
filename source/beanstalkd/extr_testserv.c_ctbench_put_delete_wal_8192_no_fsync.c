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
 int /*<<< orphan*/  bench_put_delete_size (int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
ctbench_put_delete_wal_8192_no_fsync(int n)
{
    bench_put_delete_size(n, 8192, 512000, 0, 0);
}