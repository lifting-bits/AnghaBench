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
 int AVPROBE_SCORE_MAX ; 
 int AV_RB32 (scalar_t__) ; 
 scalar_t__ AV_RL32 (scalar_t__) ; 
 scalar_t__ MKTAG (char,char,char,float) ; 

__attribute__((used)) static int aix_probe(const AVProbeData *p)
{
    if (AV_RL32(p->buf) != MKTAG('A','I','X','F') ||
        AV_RB32(p->buf +  8) != 0x01000014 ||
        AV_RB32(p->buf + 12) != 0x00000800)
        return 0;

    return AVPROBE_SCORE_MAX;
}