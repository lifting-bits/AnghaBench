#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  queue; } ;
typedef  TYPE_1__ uv_async_t ;

/* Variables and functions */
 int /*<<< orphan*/  QUEUE_REMOVE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv__async_spin (TYPE_1__*) ; 
 int /*<<< orphan*/  uv__handle_stop (TYPE_1__*) ; 

void uv__async_close(uv_async_t* handle) {
  uv__async_spin(handle);
  QUEUE_REMOVE(&handle->queue);
  uv__handle_stop(handle);
}