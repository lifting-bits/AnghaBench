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
typedef  int /*<<< orphan*/  zend_ffi_val ;

/* Variables and functions */
 int parse_conditional_expression (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int parse_constant_expression(int sym, zend_ffi_val *val) {
	sym = parse_conditional_expression(sym, val);
	return sym;
}