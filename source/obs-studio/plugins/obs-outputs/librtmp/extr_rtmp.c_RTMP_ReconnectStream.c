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
typedef  int /*<<< orphan*/  RTMP ;

/* Variables and functions */
 int RTMP_ConnectStream (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  RTMP_DeleteStream (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  RTMP_SendCreateStream (int /*<<< orphan*/ *) ; 

int
RTMP_ReconnectStream(RTMP *r, int seekTime, int streamIdx)
{
    RTMP_DeleteStream(r, streamIdx);

    RTMP_SendCreateStream(r);

    return RTMP_ConnectStream(r, seekTime);
}