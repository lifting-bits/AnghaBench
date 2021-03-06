#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* list; } ;
struct TYPE_7__ {TYPE_2__ ts; } ;
typedef  TYPE_3__ hb_stream_t ;
struct TYPE_5__ {int /*<<< orphan*/  pid; } ;

/* Variables and functions */

__attribute__((used)) static void hb_stream_delete_ts_entry(hb_stream_t *stream, int indx)
{
    if ( stream->ts.list[indx].pid > 0 )
    {
        stream->ts.list[indx].pid = -stream->ts.list[indx].pid;
    }
}