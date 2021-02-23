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
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_buf_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  tcp_handle ; 
 int /*<<< orphan*/  uv_buf_init (char*,int) ; 
 scalar_t__ uv_read_stop (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_cb ; 
 int /*<<< orphan*/  write_req ; 

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  uv_buf_t buf = uv_buf_init("PING", 4);
  ASSERT(0 == uv_write(&write_req,
                       (uv_stream_t*) &tcp_handle,
                       &buf,
                       1,
                       write_cb));
  ASSERT(0 == uv_read_stop((uv_stream_t*) &tcp_handle));
}