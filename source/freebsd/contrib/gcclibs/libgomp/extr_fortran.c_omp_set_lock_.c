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
typedef  int /*<<< orphan*/  omp_lock_arg_t ;

/* Variables and functions */
 int /*<<< orphan*/  omp_lock_arg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omp_set_lock (int /*<<< orphan*/ ) ; 

void
omp_set_lock_ (omp_lock_arg_t lock)
{
  omp_set_lock (omp_lock_arg (lock));
}