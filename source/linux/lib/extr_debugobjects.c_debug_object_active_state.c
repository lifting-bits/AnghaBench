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
struct debug_obj_descr {int dummy; } ;
struct debug_obj {int state; unsigned int astate; void* object; struct debug_obj_descr* descr; } ;
struct debug_bucket {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
#define  ODEBUG_STATE_ACTIVE 128 
 int ODEBUG_STATE_NOTAVAILABLE ; 
 int /*<<< orphan*/  debug_objects_enabled ; 
 int /*<<< orphan*/  debug_print_object (struct debug_obj*,char*) ; 
 struct debug_bucket* get_bucket (unsigned long) ; 
 struct debug_obj* lookup_object (void*,struct debug_bucket*) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

void
debug_object_active_state(void *addr, struct debug_obj_descr *descr,
			  unsigned int expect, unsigned int next)
{
	struct debug_bucket *db;
	struct debug_obj *obj;
	unsigned long flags;
	bool print_object = false;

	if (!debug_objects_enabled)
		return;

	db = get_bucket((unsigned long) addr);

	raw_spin_lock_irqsave(&db->lock, flags);

	obj = lookup_object(addr, db);
	if (obj) {
		switch (obj->state) {
		case ODEBUG_STATE_ACTIVE:
			if (obj->astate == expect)
				obj->astate = next;
			else
				print_object = true;
			break;

		default:
			print_object = true;
			break;
		}
	}

	raw_spin_unlock_irqrestore(&db->lock, flags);
	if (!obj) {
		struct debug_obj o = { .object = addr,
				       .state = ODEBUG_STATE_NOTAVAILABLE,
				       .descr = descr };

		debug_print_object(&o, "active_state");
	} else if (print_object) {
		debug_print_object(obj, "active_state");
	}
}