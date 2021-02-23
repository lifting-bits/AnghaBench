#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ buf; } ;
typedef  TYPE_1__ AVProbeData ;

/* Variables and functions */
 int APE_MAX_VERSION ; 
 int APE_MIN_VERSION ; 
 int AVPROBE_SCORE_MAX ; 
 int AV_RL16 (scalar_t__) ; 
 scalar_t__ AV_RL32 (scalar_t__) ; 
 scalar_t__ MKTAG (char,char,char,char) ; 

__attribute__((used)) static int ape_probe(const AVProbeData * p)
{
    int version = AV_RL16(p->buf+4);
    if (AV_RL32(p->buf) != MKTAG('M', 'A', 'C', ' '))
        return 0;

    if (version < APE_MIN_VERSION || version > APE_MAX_VERSION)
        return AVPROBE_SCORE_MAX/4;

    return AVPROBE_SCORE_MAX;
}