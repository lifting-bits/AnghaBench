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
typedef  int /*<<< orphan*/  zend_object ;
typedef  int /*<<< orphan*/  zend_class_entry ;

/* Variables and functions */
 int /*<<< orphan*/ * spl_filesystem_object_new_ex (int /*<<< orphan*/ *) ; 

__attribute__((used)) static zend_object *spl_filesystem_object_new(zend_class_entry *class_type)
{
	return spl_filesystem_object_new_ex(class_type);
}