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
typedef  int /*<<< orphan*/  jerry_value_t ;
typedef  int /*<<< orphan*/  jerry_char_t ;

/* Variables and functions */
 int /*<<< orphan*/  JERRY_PARSE_NO_OPTS ; 
 int /*<<< orphan*/  jerry_eval (int /*<<< orphan*/ *,size_t const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jerry_release_value (int /*<<< orphan*/ ) ; 
 scalar_t__ jerry_value_is_error (int /*<<< orphan*/ ) ; 

int js_eval (const char *source_p, const size_t source_size)
{
  jerry_value_t res = jerry_eval ((jerry_char_t *) source_p,
                                  source_size,
                                  JERRY_PARSE_NO_OPTS);
  if (jerry_value_is_error (res)) {
    jerry_release_value (res);
    return -1;
  }

  jerry_release_value (res);

  return 0;
}