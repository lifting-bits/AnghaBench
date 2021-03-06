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
struct wl_compositor {int dummy; } ;
struct vlc_wl_registry {int dummy; } ;

/* Variables and functions */
 scalar_t__ vlc_wl_interface_bind (struct vlc_wl_registry*,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wl_compositor_interface ; 

struct wl_compositor *vlc_wl_compositor_get(struct vlc_wl_registry *vr)
{
    return (struct wl_compositor *)vlc_wl_interface_bind(vr, "wl_compositor",
                                               &wl_compositor_interface, NULL);
}