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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  item ;
typedef  int /*<<< orphan*/  conn ;

/* Variables and functions */
 int /*<<< orphan*/ * do_item_touch (char const*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hash (char const*,size_t) ; 
 int /*<<< orphan*/  item_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  item_unlock (int /*<<< orphan*/ ) ; 

item *item_touch(const char *key, size_t nkey, uint32_t exptime, conn *c) {
    item *it;
    uint32_t hv;
    hv = hash(key, nkey);
    item_lock(hv);
    it = do_item_touch(key, nkey, exptime, hv, c);
    item_unlock(hv);
    return it;
}