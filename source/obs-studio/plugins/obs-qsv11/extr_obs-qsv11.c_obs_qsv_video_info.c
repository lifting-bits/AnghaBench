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
struct video_scale_info {int format; } ;
struct obs_qsv {int /*<<< orphan*/  encoder; } ;
typedef  enum video_format { ____Placeholder_video_format } video_format ;

/* Variables and functions */
 int VIDEO_FORMAT_NV12 ; 
 int /*<<< orphan*/  cap_resolution (int /*<<< orphan*/ ,struct video_scale_info*) ; 
 int obs_encoder_get_preferred_video_format (int /*<<< orphan*/ ) ; 
 scalar_t__ valid_format (int) ; 

__attribute__((used)) static void obs_qsv_video_info(void *data, struct video_scale_info *info)
{
	struct obs_qsv *obsqsv = data;
	enum video_format pref_format;

	pref_format = obs_encoder_get_preferred_video_format(obsqsv->encoder);

	if (!valid_format(pref_format)) {
		pref_format = valid_format(info->format) ? info->format
							 : VIDEO_FORMAT_NV12;
	}

	info->format = pref_format;
	cap_resolution(obsqsv->encoder, info);
}