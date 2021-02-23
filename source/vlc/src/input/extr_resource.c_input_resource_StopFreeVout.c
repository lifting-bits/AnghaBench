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
struct TYPE_3__ {int /*<<< orphan*/  lock; int /*<<< orphan*/ * p_vout_free; } ;
typedef  TYPE_1__ input_resource_t ;

/* Variables and functions */
 int /*<<< orphan*/  msg_Dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  vlc_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vout_Stop (int /*<<< orphan*/ *) ; 

void input_resource_StopFreeVout(input_resource_t *p_resource)
{
    vlc_mutex_lock(&p_resource->lock);
    if (p_resource->p_vout_free != NULL)
    {
        msg_Dbg(p_resource->p_vout_free, "stop free vout");
        vout_Stop(p_resource->p_vout_free);
    }
    vlc_mutex_unlock(&p_resource->lock);
}