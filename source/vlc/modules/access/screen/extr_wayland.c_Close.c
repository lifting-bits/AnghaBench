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
typedef  int /*<<< orphan*/  vlc_object_t ;
struct TYPE_4__ {TYPE_2__* p_sys; } ;
typedef  TYPE_1__ demux_t ;
struct TYPE_5__ {int /*<<< orphan*/  display; int /*<<< orphan*/  output; int /*<<< orphan*/  shm; int /*<<< orphan*/  screenshooter; int /*<<< orphan*/  thread; } ;
typedef  TYPE_2__ demux_sys_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 int /*<<< orphan*/  screenshooter_destroy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_cancel (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wl_display_disconnect (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_output_destroy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_shm_destroy (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void Close(vlc_object_t *obj)
{
    demux_t *demux = (demux_t *)obj;
    demux_sys_t *sys = demux->p_sys;

    vlc_cancel(sys->thread);
    vlc_join(sys->thread, NULL);

    screenshooter_destroy(sys->screenshooter);
    wl_shm_destroy(sys->shm);
    wl_output_destroy(sys->output);
    wl_display_disconnect(sys->display);
    free(sys);
}