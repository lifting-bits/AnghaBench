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
struct TYPE_5__ {TYPE_1__* priv_data; } ;
struct TYPE_4__ {int /*<<< orphan*/  q; } ;
typedef  TYPE_1__ SAMIContext ;
typedef  TYPE_2__ AVFormatContext ;

/* Variables and functions */
 int /*<<< orphan*/  ff_subtitles_queue_clean (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int sami_read_close(AVFormatContext *s)
{
    SAMIContext *sami = s->priv_data;
    ff_subtitles_queue_clean(&sami->q);
    return 0;
}