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
struct Item {int seen; } ;
typedef  int /*<<< orphan*/  OrderedSet ;

/* Variables and functions */
 int ELEMENTSOF (struct Item*) ; 
 int /*<<< orphan*/  assert_se (int) ; 
 int /*<<< orphan*/  item_hash_ops ; 
 int /*<<< orphan*/ * ordered_set_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ordered_set_new (int /*<<< orphan*/ *) ; 
 int ordered_set_put (int /*<<< orphan*/ *,struct Item*) ; 

__attribute__((used)) static void test_set_free_with_hash_ops(void) {
        OrderedSet *m;
        struct Item items[4] = {};
        unsigned i;

        assert_se(m = ordered_set_new(&item_hash_ops));
        for (i = 0; i < ELEMENTSOF(items) - 1; i++)
                assert_se(ordered_set_put(m, items + i) == 1);

        m = ordered_set_free(m);
        assert_se(items[0].seen == 1);
        assert_se(items[1].seen == 1);
        assert_se(items[2].seen == 1);
        assert_se(items[3].seen == 0);
}