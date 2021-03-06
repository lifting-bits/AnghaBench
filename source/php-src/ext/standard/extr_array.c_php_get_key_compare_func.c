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
typedef  int zend_long ;
typedef  int /*<<< orphan*/ * compare_func_t ;

/* Variables and functions */
 int PHP_SORT_FLAG_CASE ; 
#define  PHP_SORT_LOCALE_STRING 132 
#define  PHP_SORT_NATURAL 131 
#define  PHP_SORT_NUMERIC 130 
#define  PHP_SORT_REGULAR 129 
#define  PHP_SORT_STRING 128 
 int /*<<< orphan*/ * php_array_key_compare ; 
 int /*<<< orphan*/ * php_array_key_compare_numeric ; 
 int /*<<< orphan*/ * php_array_key_compare_string ; 
 int /*<<< orphan*/ * php_array_key_compare_string_case ; 
 int /*<<< orphan*/ * php_array_key_compare_string_locale ; 
 int /*<<< orphan*/ * php_array_key_compare_string_natural ; 
 int /*<<< orphan*/ * php_array_key_compare_string_natural_case ; 
 int /*<<< orphan*/ * php_array_reverse_key_compare ; 
 int /*<<< orphan*/ * php_array_reverse_key_compare_numeric ; 
 int /*<<< orphan*/ * php_array_reverse_key_compare_string ; 
 int /*<<< orphan*/ * php_array_reverse_key_compare_string_case ; 
 int /*<<< orphan*/ * php_array_reverse_key_compare_string_locale ; 
 int /*<<< orphan*/ * php_array_reverse_key_compare_string_natural ; 
 int /*<<< orphan*/ * php_array_reverse_key_compare_string_natural_case ; 

__attribute__((used)) static compare_func_t php_get_key_compare_func(zend_long sort_type, int reverse) /* {{{ */
{
	switch (sort_type & ~PHP_SORT_FLAG_CASE) {
		case PHP_SORT_NUMERIC:
			if (reverse) {
				return php_array_reverse_key_compare_numeric;
			} else {
				return php_array_key_compare_numeric;
			}
			break;

		case PHP_SORT_STRING:
			if (sort_type & PHP_SORT_FLAG_CASE) {
				if (reverse) {
					return php_array_reverse_key_compare_string_case;
				} else {
					return php_array_key_compare_string_case;
				}
			} else {
				if (reverse) {
					return php_array_reverse_key_compare_string;
				} else {
					return php_array_key_compare_string;
				}
			}
			break;

		case PHP_SORT_NATURAL:
			if (sort_type & PHP_SORT_FLAG_CASE) {
				if (reverse) {
					return php_array_reverse_key_compare_string_natural_case;
				} else {
					return php_array_key_compare_string_natural_case;
				}
			} else {
				if (reverse) {
					return php_array_reverse_key_compare_string_natural;
				} else {
					return php_array_key_compare_string_natural;
				}
			}
			break;

		case PHP_SORT_LOCALE_STRING:
			if (reverse) {
				return php_array_reverse_key_compare_string_locale;
			} else {
				return php_array_key_compare_string_locale;
			}
			break;

		case PHP_SORT_REGULAR:
		default:
			if (reverse) {
				return php_array_reverse_key_compare;
			} else {
				return php_array_key_compare;
			}
			break;
	}
	return NULL;
}