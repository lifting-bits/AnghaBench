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
struct filter_pred {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int filter_pred_or(struct filter_pred *pred __attribute((unused)),
			  void *event __attribute((unused)),
			  int val1, int val2)
{
	return val1 || val2;
}