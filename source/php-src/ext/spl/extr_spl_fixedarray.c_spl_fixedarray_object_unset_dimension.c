#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zval ;
typedef  int /*<<< orphan*/  zend_object ;
struct TYPE_5__ {int /*<<< orphan*/  ce; } ;
struct TYPE_6__ {scalar_t__ fptr_offset_del; TYPE_1__ std; } ;
typedef  TYPE_2__ spl_fixedarray_object ;

/* Variables and functions */
 int /*<<< orphan*/  SEPARATE_ARG_IF_REF (int /*<<< orphan*/ *) ; 
 TYPE_2__* spl_fixed_array_from_obj (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spl_fixedarray_object_unset_dimension_helper (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zend_call_method_with_1_params (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zval_ptr_dtor (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void spl_fixedarray_object_unset_dimension(zend_object *object, zval *offset) /* {{{ */
{
	spl_fixedarray_object *intern;

	intern = spl_fixed_array_from_obj(object);

	if (intern->fptr_offset_del) {
		SEPARATE_ARG_IF_REF(offset);
		zend_call_method_with_1_params(object, intern->std.ce, &intern->fptr_offset_del, "offsetUnset", NULL, offset);
		zval_ptr_dtor(offset);
		return;
	}

	spl_fixedarray_object_unset_dimension_helper(intern, offset);

}