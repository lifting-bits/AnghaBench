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
struct stm_object {int /*<<< orphan*/  lock; int /*<<< orphan*/ * copy; int /*<<< orphan*/  reference; } ;

/* Variables and functions */
 scalar_t__ ATOM_DEC (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rwlock_rlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rwlock_runlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skynet_free (struct stm_object*) ; 

__attribute__((used)) static void
stm_releasereader(struct stm_object *obj) {
	rwlock_rlock(&obj->lock);
	if (ATOM_DEC(&obj->reference) == 0) {
		// last reader, no writer. so no need to unlock
		assert(obj->copy == NULL);
		skynet_free(obj);
		return;
	}
	rwlock_runlock(&obj->lock);
}