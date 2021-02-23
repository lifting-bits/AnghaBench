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
struct TYPE_4__ {int /*<<< orphan*/ * DPB; } ;
typedef  TYPE_1__ HEVCContext ;

/* Variables and functions */
 int FF_ARRAY_ELEMS (int /*<<< orphan*/ *) ; 
 int HEVC_FRAME_FLAG_LONG_REF ; 
 int HEVC_FRAME_FLAG_SHORT_REF ; 
 int /*<<< orphan*/  ff_hevc_unref_frame (TYPE_1__*,int /*<<< orphan*/ *,int) ; 

void ff_hevc_clear_refs(HEVCContext *s)
{
    int i;
    for (i = 0; i < FF_ARRAY_ELEMS(s->DPB); i++)
        ff_hevc_unref_frame(s, &s->DPB[i],
                            HEVC_FRAME_FLAG_SHORT_REF |
                            HEVC_FRAME_FLAG_LONG_REF);
}