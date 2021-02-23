#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ jerryx_handle_scope_status ;
typedef  TYPE_1__* jerryx_escapable_handle_scope ;
typedef  int /*<<< orphan*/  jerry_value_t ;
struct TYPE_6__ {scalar_t__ prelist_handle_count; int /*<<< orphan*/ * handle_ptr; } ;

/* Variables and functions */
 int /*<<< orphan*/  TEST_ASSERT (int) ; 
 int /*<<< orphan*/  jerry_create_object () ; 
 int /*<<< orphan*/  jerry_set_object_native_pointer (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  jerryx_close_handle_scope (TYPE_1__*) ; 
 int /*<<< orphan*/  jerryx_create_handle (int /*<<< orphan*/ ) ; 
 scalar_t__ jerryx_escape_handle (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_1__* jerryx_handle_scope_get_current () ; 
 scalar_t__ jerryx_handle_scope_ok ; 
 int /*<<< orphan*/  jerryx_open_escapable_handle_scope (TYPE_1__**) ; 
 int /*<<< orphan*/  native_info ; 

__attribute__((used)) static jerry_value_t
create_object_nested (int times)
{
  jerryx_escapable_handle_scope scope;
  jerryx_open_escapable_handle_scope (&scope);

  jerry_value_t obj;
  if (times == 0)
  {
    obj = jerryx_create_handle (jerry_create_object ());
    jerry_set_object_native_pointer (obj, NULL, &native_info);
  }
  else
  {
    obj = create_object_nested (times - 1);
  }
  TEST_ASSERT (jerryx_handle_scope_get_current () == scope);

  // If leaves `escaped` uninitialized, there will be a style error on linux thrown by compiler
  jerry_value_t escaped = 0;
  jerryx_handle_scope_status status = jerryx_escape_handle (scope, obj, &escaped);
  TEST_ASSERT (status == jerryx_handle_scope_ok);
  TEST_ASSERT (scope->prelist_handle_count == 0);
  TEST_ASSERT (scope->handle_ptr == NULL);

  jerryx_close_handle_scope (scope);
  return escaped;
}