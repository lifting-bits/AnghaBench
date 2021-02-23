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
 int /*<<< orphan*/  ECMA_ERR_MSG (char*) ; 
 int /*<<< orphan*/  JERRY_ASSERT (int) ; 
 int /*<<< orphan*/  ecma_raise_type_error (int /*<<< orphan*/ ) ; 

ecma_value_t
ecma_builtin_type_error_thrower_dispatch_call (const ecma_value_t *arguments_list_p, /**< arguments list */
                                               ecma_length_t arguments_list_len) /**< number of arguments */
{
  JERRY_ASSERT (arguments_list_len == 0 || arguments_list_p != NULL);

  /* The object should throw TypeError */
  return ecma_raise_type_error (ECMA_ERR_MSG (""));
}