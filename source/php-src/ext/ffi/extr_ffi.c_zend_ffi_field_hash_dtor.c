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
typedef  int /*<<< orphan*/  zval ;
struct TYPE_4__ {int /*<<< orphan*/  type; } ;
typedef  TYPE_1__ zend_ffi_field ;

/* Variables and functions */
 TYPE_1__* Z_PTR_P (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  efree (TYPE_1__*) ; 
 int /*<<< orphan*/  zend_ffi_type_dtor (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void zend_ffi_field_hash_dtor(zval *zv) /* {{{ */
{
	zend_ffi_field *field = Z_PTR_P(zv);
	zend_ffi_type_dtor(field->type);
	efree(field);
}