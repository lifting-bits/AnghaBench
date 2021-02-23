#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int extra; } ;
typedef  TYPE_1__ item_t ;

/* Variables and functions */
 int FLAG_DELETED ; 
 int /*<<< orphan*/  ONLY_FIND ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ get_idx_item (long long) ; 
 TYPE_1__* get_item_f (long long,int /*<<< orphan*/ ) ; 
 int get_rate_item (TYPE_1__*,int) ; 
 int /*<<< orphan*/  vkprintf (int,char*,long long,TYPE_1__*,TYPE_1__*) ; 

int get_single_rate (int *rate, long long item_id, int p) {
  item_t *I = get_item_f (item_id, ONLY_FIND);
  item_t *II = (item_t *) get_idx_item (item_id);

  vkprintf (2, "get_single_rate(%016llx): %p %p\n", item_id, I, II);

  if (II) {
    assert (!I);
    *rate = get_rate_item (II, p);
    return 1;
  }

  if (!I || (I->extra & FLAG_DELETED)) {
    return 0;
  }
  *rate = get_rate_item (I, p);
  return 1;
}