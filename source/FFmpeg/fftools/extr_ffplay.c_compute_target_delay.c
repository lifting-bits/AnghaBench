#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {scalar_t__ max_frame_duration; int /*<<< orphan*/  vidclk; } ;
typedef  TYPE_1__ VideoState ;

/* Variables and functions */
 int /*<<< orphan*/  AV_LOG_TRACE ; 
 double AV_SYNC_FRAMEDUP_THRESHOLD ; 
 int /*<<< orphan*/  AV_SYNC_THRESHOLD_MAX ; 
 int /*<<< orphan*/  AV_SYNC_THRESHOLD_MIN ; 
 scalar_t__ AV_SYNC_VIDEO_MASTER ; 
 double FFMAX (int /*<<< orphan*/ ,double) ; 
 double FFMIN (int /*<<< orphan*/ ,double) ; 
 int /*<<< orphan*/  av_log (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,double,double) ; 
 scalar_t__ fabs (double) ; 
 double get_clock (int /*<<< orphan*/ *) ; 
 double get_master_clock (TYPE_1__*) ; 
 scalar_t__ get_master_sync_type (TYPE_1__*) ; 
 int /*<<< orphan*/  isnan (double) ; 

__attribute__((used)) static double compute_target_delay(double delay, VideoState *is)
{
    double sync_threshold, diff = 0;

    /* update delay to follow master synchronisation source */
    if (get_master_sync_type(is) != AV_SYNC_VIDEO_MASTER) {
        /* if video is slave, we try to correct big delays by
           duplicating or deleting a frame */
        diff = get_clock(&is->vidclk) - get_master_clock(is);

        /* skip or repeat frame. We take into account the
           delay to compute the threshold. I still don't know
           if it is the best guess */
        sync_threshold = FFMAX(AV_SYNC_THRESHOLD_MIN, FFMIN(AV_SYNC_THRESHOLD_MAX, delay));
        if (!isnan(diff) && fabs(diff) < is->max_frame_duration) {
            if (diff <= -sync_threshold)
                delay = FFMAX(0, delay + diff);
            else if (diff >= sync_threshold && delay > AV_SYNC_FRAMEDUP_THRESHOLD)
                delay = delay + diff;
            else if (diff >= sync_threshold)
                delay = 2 * delay;
        }
    }

    av_log(NULL, AV_LOG_TRACE, "video: delay=%0.3f A-V=%f\n",
            delay, -diff);

    return delay;
}