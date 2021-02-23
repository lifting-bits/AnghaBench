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
typedef  int /*<<< orphan*/  zend_property_info ;
typedef  int /*<<< orphan*/  zend_class_entry ;
struct TYPE_4__ {int /*<<< orphan*/  const* parent_prop; int /*<<< orphan*/  const* child_prop; int /*<<< orphan*/  type; } ;
typedef  TYPE_1__ variance_obligation ;
typedef  int /*<<< orphan*/  HashTable ;

/* Variables and functions */
 int /*<<< orphan*/  OBLIGATION_PROPERTY_COMPATIBILITY ; 
 TYPE_1__* emalloc (int) ; 
 int /*<<< orphan*/ * get_or_init_obligations_for_class (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zend_hash_next_index_insert_ptr (int /*<<< orphan*/ *,TYPE_1__*) ; 

__attribute__((used)) static void add_property_compatibility_obligation(
		zend_class_entry *ce, const zend_property_info *child_prop,
		const zend_property_info *parent_prop) {
	HashTable *obligations = get_or_init_obligations_for_class(ce);
	variance_obligation *obligation = emalloc(sizeof(variance_obligation));
	obligation->type = OBLIGATION_PROPERTY_COMPATIBILITY;
	obligation->child_prop = child_prop;
	obligation->parent_prop = parent_prop;
	zend_hash_next_index_insert_ptr(obligations, obligation);
}