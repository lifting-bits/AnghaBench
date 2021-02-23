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
struct TYPE_6__ {TYPE_3__* p; } ;
typedef  TYPE_2__ vout_thread_t ;
struct TYPE_5__ {int is_display_filled; } ;
struct TYPE_7__ {int /*<<< orphan*/  display_lock; int /*<<< orphan*/ * display; int /*<<< orphan*/  window_lock; TYPE_1__ display_cfg; int /*<<< orphan*/  dummy; } ;
typedef  TYPE_3__ vout_thread_sys_t ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  vlc_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vout_SetDisplayFilled (int /*<<< orphan*/ *,int) ; 

void vout_ChangeDisplayFilled(vout_thread_t *vout, bool is_filled)
{
    vout_thread_sys_t *sys = vout->p;
    assert(!sys->dummy);

    vlc_mutex_lock(&sys->window_lock);
    sys->display_cfg.is_display_filled = is_filled;
    /* no window size update here */

    vlc_mutex_lock(&sys->display_lock);
    vlc_mutex_unlock(&sys->window_lock);

    if (sys->display != NULL)
        vout_SetDisplayFilled(sys->display, is_filled);
    vlc_mutex_unlock(&sys->display_lock);
}