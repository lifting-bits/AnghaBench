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
typedef  scalar_t__ ecma_length_t ;

/* Variables and functions */
 int /*<<< orphan*/  JERRY_ASSERT (int) ; 
 int /*<<< orphan*/  ecma_builtin_object_dispatch_construct (int /*<<< orphan*/  const*,scalar_t__) ; 
 scalar_t__ ecma_is_value_null (int /*<<< orphan*/  const) ; 
 scalar_t__ ecma_is_value_undefined (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  ecma_op_to_object (int /*<<< orphan*/  const) ; 

ecma_value_t
ecma_builtin_object_dispatch_call (const ecma_value_t *arguments_list_p, /**< arguments list */
                                   ecma_length_t arguments_list_len) /**< number of arguments */
{
  JERRY_ASSERT (arguments_list_len == 0 || arguments_list_p != NULL);

  if (arguments_list_len == 0
      || ecma_is_value_undefined (arguments_list_p[0])
      || ecma_is_value_null (arguments_list_p[0]))
  {
    return ecma_builtin_object_dispatch_construct (arguments_list_p, arguments_list_len);
  }

  return ecma_op_to_object (arguments_list_p[0]);
}