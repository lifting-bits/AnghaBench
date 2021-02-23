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
struct v4l2_buffer {int dummy; } ;
struct file {int dummy; } ;
struct cx8800_fh {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  get_queue (struct cx8800_fh*) ; 
 int videobuf_querybuf (int /*<<< orphan*/ ,struct v4l2_buffer*) ; 

__attribute__((used)) static int vidioc_querybuf (struct file *file, void *priv, struct v4l2_buffer *p)
{
	struct cx8800_fh  *fh   = priv;
	return (videobuf_querybuf(get_queue(fh), p));
}