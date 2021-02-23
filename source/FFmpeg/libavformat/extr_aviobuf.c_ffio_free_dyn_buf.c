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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  AVIOContext ;

/* Variables and functions */
 int /*<<< orphan*/  av_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  avio_close_dyn_buf (int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 

void ffio_free_dyn_buf(AVIOContext **s)
{
    uint8_t *tmp;
    if (!*s)
        return;
    avio_close_dyn_buf(*s, &tmp);
    av_free(tmp);
    *s = NULL;
}