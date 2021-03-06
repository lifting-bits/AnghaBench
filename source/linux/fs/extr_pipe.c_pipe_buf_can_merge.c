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
struct pipe_buffer {int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  anon_pipe_buf_ops ; 

__attribute__((used)) static bool pipe_buf_can_merge(struct pipe_buffer *buf)
{
	return buf->ops == &anon_pipe_buf_ops;
}