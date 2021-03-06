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
struct vpif_fh {struct channel_obj* channel; } ;
struct video_obj {unsigned int output_id; } ;
struct file {int dummy; } ;
struct channel_obj {struct video_obj video; } ;

/* Variables and functions */

__attribute__((used)) static int vpif_g_output(struct file *file, void *priv, unsigned int *i)
{
	struct vpif_fh *fh = priv;
	struct channel_obj *ch = fh->channel;
	struct video_obj *vid_ch = &ch->video;

	*i = vid_ch->output_id;

	return 0;
}