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
struct v4l2_fmtdesc {int index; int /*<<< orphan*/  pixelformat; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  V4L2_PIX_FMT_MJPEG ; 
 int /*<<< orphan*/  V4L2_PIX_FMT_MPEG1 ; 
 int /*<<< orphan*/  V4L2_PIX_FMT_MPEG2 ; 
 int /*<<< orphan*/  V4L2_PIX_FMT_MPEG4 ; 

__attribute__((used)) static int vidioc_enum_fmt_vid_cap(struct file *file, void  *priv,
					struct v4l2_fmtdesc *fmt)
{
	switch (fmt->index) {
	case 0:
		fmt->pixelformat = V4L2_PIX_FMT_MJPEG;
		break;
	case 1:
		fmt->pixelformat = V4L2_PIX_FMT_MPEG1;
		break;
	case 2:
		fmt->pixelformat = V4L2_PIX_FMT_MPEG2;
		break;
	case 3:
		fmt->pixelformat = V4L2_PIX_FMT_MPEG4;
		break;
	default:
		return -EINVAL;
	}
	return 0;
}