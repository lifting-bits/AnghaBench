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
struct pipe_inode_info {int dummy; } ;
struct pipe_buffer {scalar_t__ private; } ;
struct buffer_ref {int /*<<< orphan*/  page; int /*<<< orphan*/  buffer; scalar_t__ ref; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct buffer_ref*) ; 
 int /*<<< orphan*/  ring_buffer_free_read_page (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void buffer_pipe_buf_release(struct pipe_inode_info *pipe,
				    struct pipe_buffer *buf)
{
	struct buffer_ref *ref = (struct buffer_ref *)buf->private;

	if (--ref->ref)
		return;

	ring_buffer_free_read_page(ref->buffer, ref->page);
	kfree(ref);
	buf->private = 0;
}