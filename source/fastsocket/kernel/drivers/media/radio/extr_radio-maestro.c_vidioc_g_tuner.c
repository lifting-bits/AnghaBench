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
struct v4l2_tuner {scalar_t__ index; int rxsubchans; int /*<<< orphan*/  signal; int /*<<< orphan*/  audmode; int /*<<< orphan*/  capability; int /*<<< orphan*/  rangehigh; int /*<<< orphan*/  rangelow; int /*<<< orphan*/  type; int /*<<< orphan*/  name; } ;
struct maestro {int /*<<< orphan*/  lock; int /*<<< orphan*/  tuned; scalar_t__ stereo; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  FREQ_HI ; 
 int /*<<< orphan*/  FREQ_LO ; 
 int /*<<< orphan*/  V4L2_TUNER_CAP_LOW ; 
 int /*<<< orphan*/  V4L2_TUNER_MODE_MONO ; 
 int /*<<< orphan*/  V4L2_TUNER_MODE_STEREO ; 
 int /*<<< orphan*/  V4L2_TUNER_RADIO ; 
 int V4L2_TUNER_SUB_MONO ; 
 int V4L2_TUNER_SUB_STEREO ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  radio_bits_get (struct maestro*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 struct maestro* video_drvdata (struct file*) ; 

__attribute__((used)) static int vidioc_g_tuner(struct file *file, void *priv,
					struct v4l2_tuner *v)
{
	struct maestro *dev = video_drvdata(file);

	if (v->index > 0)
		return -EINVAL;

	mutex_lock(&dev->lock);
	radio_bits_get(dev);

	strlcpy(v->name, "FM", sizeof(v->name));
	v->type = V4L2_TUNER_RADIO;
	v->rangelow = FREQ_LO;
	v->rangehigh = FREQ_HI;
	v->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
	v->capability = V4L2_TUNER_CAP_LOW;
	if (dev->stereo)
		v->audmode = V4L2_TUNER_MODE_STEREO;
	else
		v->audmode = V4L2_TUNER_MODE_MONO;
	v->signal = dev->tuned;
	mutex_unlock(&dev->lock);
	return 0;
}