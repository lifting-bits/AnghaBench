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
typedef  int /*<<< orphan*/  uv_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  conn ; 
 int /*<<< orphan*/  timer ; 

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(handle == (uv_handle_t*)&conn || handle == (uv_handle_t*)&timer);
  close_cb_called++;
}