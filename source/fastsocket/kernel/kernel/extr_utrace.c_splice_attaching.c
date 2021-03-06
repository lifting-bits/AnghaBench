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
struct utrace {scalar_t__ pending_attach; int /*<<< orphan*/  attached; int /*<<< orphan*/  attaching; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_splice_tail_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void splice_attaching(struct utrace *utrace)
{
	lockdep_assert_held(&utrace->lock);
	list_splice_tail_init(&utrace->attaching, &utrace->attached);
	utrace->pending_attach = 0;
}