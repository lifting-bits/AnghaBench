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
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  huge_timer1 ; 
 int /*<<< orphan*/  tiny_timer ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void huge_repeat_cb(uv_timer_t* handle) {
  static int ncalls;

  if (ncalls == 0)
    ASSERT(handle == &huge_timer1);
  else
    ASSERT(handle == &tiny_timer);

  if (++ncalls == 10) {
    uv_close((uv_handle_t*) &tiny_timer, NULL);
    uv_close((uv_handle_t*) &huge_timer1, NULL);
  }
}