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
struct rpc_buffer {scalar_t__ rptr; } ;

/* Variables and functions */
 int /*<<< orphan*/  buffer_check_len_rptr (struct rpc_buffer*,int) ; 

__attribute__((used)) static inline int buffer_read_int (struct rpc_buffer *buf, int *x) {
  if (!buffer_check_len_rptr (buf, 4)) {
    return -1;
  } else {
    *x = *(int *)buf->rptr;
    buf->rptr += 4;
    return 1;
  }
}