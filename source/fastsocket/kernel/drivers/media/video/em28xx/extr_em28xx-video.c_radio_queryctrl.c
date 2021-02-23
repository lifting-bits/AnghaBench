#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct v4l2_queryctrl {scalar_t__ id; } ;
struct file {int dummy; } ;
struct TYPE_4__ {scalar_t__ id; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 scalar_t__ V4L2_CID_BASE ; 
 scalar_t__ V4L2_CID_LASTP1 ; 
 TYPE_1__* ac97_qctrl ; 
 int /*<<< orphan*/  memcpy (struct v4l2_queryctrl*,TYPE_1__*,int) ; 

__attribute__((used)) static int radio_queryctrl(struct file *file, void *priv,
			   struct v4l2_queryctrl *qc)
{
	int i;

	if (qc->id <  V4L2_CID_BASE ||
		qc->id >= V4L2_CID_LASTP1)
		return -EINVAL;

	for (i = 0; i < ARRAY_SIZE(ac97_qctrl); i++) {
		if (qc->id && qc->id == ac97_qctrl[i].id) {
			memcpy(qc, &(ac97_qctrl[i]), sizeof(*qc));
			return 0;
		}
	}

	return -EINVAL;
}