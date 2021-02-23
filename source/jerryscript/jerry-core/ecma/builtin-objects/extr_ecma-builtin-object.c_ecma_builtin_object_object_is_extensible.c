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
typedef  int /*<<< orphan*/  ecma_value_t ;
typedef  int /*<<< orphan*/  ecma_object_t ;

/* Variables and functions */
 int /*<<< orphan*/  ecma_get_object_extensible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ecma_make_boolean_value (int /*<<< orphan*/ ) ; 

ecma_value_t
ecma_builtin_object_object_is_extensible (ecma_object_t *obj_p) /**< routine's argument */
{
  return ecma_make_boolean_value (ecma_get_object_extensible (obj_p));
}