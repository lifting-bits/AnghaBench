#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int int64_t ;
struct TYPE_5__ {TYPE_1__* frame_info; } ;
typedef  TYPE_2__ hb_work_private_t ;
struct TYPE_4__ {int duration; } ;

/* Variables and functions */
 int FRAME_INFO_MASK ; 

__attribute__((used)) static int64_t get_frame_duration( hb_work_private_t * pv, int64_t frameno )
{
    int i = frameno & FRAME_INFO_MASK;
    return pv->frame_info[i].duration;
}