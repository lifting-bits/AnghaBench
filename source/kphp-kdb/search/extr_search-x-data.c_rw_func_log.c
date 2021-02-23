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
struct rate_weight {int /*<<< orphan*/  p; } ;
struct item {int dummy; } ;

/* Variables and functions */
 scalar_t__ INT_MIN ; 
 unsigned int get_rate_item_fast (struct item*,int /*<<< orphan*/ ) ; 
 double log (unsigned int) ; 

__attribute__((used)) static double rw_func_log (struct item *I, struct rate_weight *R) {
  unsigned rate = get_rate_item_fast (I, R->p);
  rate -= INT_MIN;
  if (rate == -1U) { return 0.0; }
  return 1.0 - (log (rate + 1) * 0.04508422002825);
}