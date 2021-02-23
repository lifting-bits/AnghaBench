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
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  FilterLoop26_C (int /*<<< orphan*/ *,int,int,int,int,int,int) ; 

__attribute__((used)) static void HFilter8_C(uint8_t* u, uint8_t* v, int stride,
                       int thresh, int ithresh, int hev_thresh) {
  FilterLoop26_C(u, 1, stride, 8, thresh, ithresh, hev_thresh);
  FilterLoop26_C(v, 1, stride, 8, thresh, ithresh, hev_thresh);
}