#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int extra; } ;
typedef  TYPE_1__ item_t ;

/* Variables and functions */
 int FLAG_DELETED ; 
 int /*<<< orphan*/  ONLY_FIND ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ get_idx_item (long long) ; 
 TYPE_1__* get_item_f (long long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_rate_item (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  vkprintf (int,char*,long long,int,int) ; 

__attribute__((used)) static int set_rate_new (long long item_id, int p, int rate) {
  vkprintf (4, "set_rate_new(%016llx), p = %d, rate = %d\n", item_id, p, rate);

  item_t *I = get_item_f (item_id, ONLY_FIND);
  item_t *II = (item_t *) get_idx_item (item_id);

  if (II) {
    set_rate_item (II, p, rate);
    assert (!I);
    return 1;
  }

  if (!I || (I->extra & FLAG_DELETED)) {
    return 0;
  }
  set_rate_item (I, p, rate);
  return 1;
}