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
typedef  long long int64_t ;
struct TYPE_3__ {int lfe_channel; } ;
typedef  TYPE_1__ HeadphoneContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 long long AV_CH_LOW_FREQUENCY ; 
 int /*<<< orphan*/  EINVAL ; 
 long long av_get_channel_layout (char*) ; 
 scalar_t__ sscanf (char*,char*,char*,int*) ; 

__attribute__((used)) static int parse_channel_name(HeadphoneContext *s, int x, char **arg, int *rchannel, char *buf)
{
    int len, i, channel_id = 0;
    int64_t layout, layout0;

    if (sscanf(*arg, "%7[A-Z]%n", buf, &len)) {
        layout0 = layout = av_get_channel_layout(buf);
        if (layout == AV_CH_LOW_FREQUENCY)
            s->lfe_channel = x;
        for (i = 32; i > 0; i >>= 1) {
            if (layout >= 1LL << i) {
                channel_id += i;
                layout >>= i;
            }
        }
        if (channel_id >= 64 || layout0 != 1LL << channel_id)
            return AVERROR(EINVAL);
        *rchannel = channel_id;
        *arg += len;
        return 0;
    }
    return AVERROR(EINVAL);
}