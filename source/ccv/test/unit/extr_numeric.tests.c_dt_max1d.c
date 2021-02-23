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
 int /*<<< orphan*/  dt_max_helper (float*,float*,int*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,float,float) ; 

void dt_max1d(float *src, float *dst, int *ptr, int step, int n, 
	  float a, float b) {
  dt_max_helper(src, dst, ptr, step, 0, n-1, 0, n-1, a, b);
}