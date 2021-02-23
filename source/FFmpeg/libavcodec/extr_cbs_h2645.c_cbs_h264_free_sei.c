#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_2__ {int payload_count; int /*<<< orphan*/ * payload; } ;
typedef  TYPE_1__ H264RawSEI ;

/* Variables and functions */
 int /*<<< orphan*/  av_freep (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  cbs_h264_free_sei_payload (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void cbs_h264_free_sei(void *opaque, uint8_t *content)
{
    H264RawSEI *sei = (H264RawSEI*)content;
    int i;
    for (i = 0; i < sei->payload_count; i++)
        cbs_h264_free_sei_payload(&sei->payload[i]);
    av_freep(&content);
}