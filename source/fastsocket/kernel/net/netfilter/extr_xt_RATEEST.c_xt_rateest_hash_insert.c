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
struct xt_rateest {int /*<<< orphan*/  list; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  hlist_add_head (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * rateest_hash ; 
 unsigned int xt_rateest_hash (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void xt_rateest_hash_insert(struct xt_rateest *est)
{
	unsigned int h;

	h = xt_rateest_hash(est->name);
	hlist_add_head(&est->list, &rateest_hash[h]);
}