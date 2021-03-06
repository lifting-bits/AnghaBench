#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * data; } ;
typedef  TYPE_1__ uv_timer_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * close_cb ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void timer_cb_close_handle(uv_timer_t* timer) {
  uv_handle_t* handle;

  ASSERT(timer != NULL);
  handle = timer->data;

  uv_close((uv_handle_t*)timer, NULL);
  uv_close((uv_handle_t*)handle, close_cb);
}