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
typedef  int /*<<< orphan*/  uv_connect_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int UV_ENOENT ; 
 int /*<<< orphan*/  close_cb ; 
 int /*<<< orphan*/  connect_cb_called ; 
 int /*<<< orphan*/  pipe_handle ; 
 int /*<<< orphan*/  prepare_handle ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void connect_cb(uv_connect_t* connect_req, int status) {
  ASSERT(status == UV_ENOENT);
  connect_cb_called++;
  uv_close((uv_handle_t*)&prepare_handle, close_cb);
  uv_close((uv_handle_t*)&pipe_handle, close_cb);
}