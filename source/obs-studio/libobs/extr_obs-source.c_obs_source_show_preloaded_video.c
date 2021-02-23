#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;
struct TYPE_6__ {int async_active; scalar_t__ monitoring_type; int /*<<< orphan*/  audio_buf_mutex; int /*<<< orphan*/  last_frame_ts; } ;
typedef  TYPE_1__ obs_source_t ;

/* Variables and functions */
 scalar_t__ OBS_MONITORING_TYPE_MONITOR_ONLY ; 
 int /*<<< orphan*/  obs_source_valid (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  os_gettime_ns () ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  reset_audio_data (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reset_audio_timing (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void obs_source_show_preloaded_video(obs_source_t *source)
{
	uint64_t sys_ts;

	if (!obs_source_valid(source, "obs_source_show_preloaded_video"))
		return;

	source->async_active = true;

	pthread_mutex_lock(&source->audio_buf_mutex);
	sys_ts = (source->monitoring_type != OBS_MONITORING_TYPE_MONITOR_ONLY)
			 ? os_gettime_ns()
			 : 0;
	reset_audio_timing(source, source->last_frame_ts, sys_ts);
	reset_audio_data(source, sys_ts);
	pthread_mutex_unlock(&source->audio_buf_mutex);
}