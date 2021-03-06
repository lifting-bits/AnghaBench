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
struct solo_dev {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 scalar_t__ erase_off (struct solo_dev*) ; 
 int solo_v4l2_set_ch (struct solo_dev*,unsigned int) ; 
 struct solo_dev* video_drvdata (struct file*) ; 

__attribute__((used)) static int solo_set_input(struct file *file, void *priv, unsigned int index)
{
	struct solo_dev *solo_dev = video_drvdata(file);
	int ret = solo_v4l2_set_ch(solo_dev, index);

	if (!ret) {
		while (erase_off(solo_dev))
			/* Do nothing */;
	}

	return ret;
}