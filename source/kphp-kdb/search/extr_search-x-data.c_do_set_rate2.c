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
struct lev_search_set_rate {long long obj_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  LEV_SEARCH_SET_RATE2 ; 
 struct lev_search_set_rate* alloc_log_event (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  fits (long long) ; 
 int set_rate2 (long long,int) ; 

int do_set_rate2 (long long item_id, int rate2) {
  if (!fits (item_id)) { return 0; }
  struct lev_search_set_rate *LR = alloc_log_event (LEV_SEARCH_SET_RATE2, 16, rate2);
  LR->obj_id = item_id;
  return set_rate2 (item_id, rate2);
}