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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  APP_ERROR_CHECK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  APP_TIMER_APPSH_INIT (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  APP_TIMER_MAX_TIMERS ; 
 int /*<<< orphan*/  APP_TIMER_MODE_REPEATED ; 
 int /*<<< orphan*/  APP_TIMER_OP_QUEUE_SIZE ; 
 int /*<<< orphan*/  APP_TIMER_PRESCALER ; 
 int /*<<< orphan*/  app_timer_create (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  m_sys_timer_id ; 
 int /*<<< orphan*/  system_timer_callback ; 

__attribute__((used)) static void timers_init(void)
{
  uint32_t err_code;

  // Initialize timer module.
  APP_TIMER_APPSH_INIT(APP_TIMER_PRESCALER, APP_TIMER_MAX_TIMERS, APP_TIMER_OP_QUEUE_SIZE, true);

  // Create timers.
  err_code = app_timer_create(&m_sys_timer_id,
      APP_TIMER_MODE_REPEATED,
      system_timer_callback);
  APP_ERROR_CHECK(err_code);
}