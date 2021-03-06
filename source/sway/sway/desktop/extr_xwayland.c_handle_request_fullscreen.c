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
struct wlr_xwayland_surface {int /*<<< orphan*/  fullscreen; int /*<<< orphan*/  mapped; } ;
struct wl_listener {int dummy; } ;
struct sway_view {int /*<<< orphan*/  container; struct wlr_xwayland_surface* wlr_xwayland_surface; } ;
struct sway_xwayland_view {struct sway_view view; } ;

/* Variables and functions */
 int /*<<< orphan*/  arrange_root () ; 
 int /*<<< orphan*/  container_set_fullscreen (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  request_fullscreen ; 
 int /*<<< orphan*/  transaction_commit_dirty () ; 
 struct sway_xwayland_view* wl_container_of (struct wl_listener*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct sway_xwayland_view* xwayland_view ; 

__attribute__((used)) static void handle_request_fullscreen(struct wl_listener *listener, void *data) {
	struct sway_xwayland_view *xwayland_view =
		wl_container_of(listener, xwayland_view, request_fullscreen);
	struct sway_view *view = &xwayland_view->view;
	struct wlr_xwayland_surface *xsurface = view->wlr_xwayland_surface;
	if (!xsurface->mapped) {
		return;
	}
	container_set_fullscreen(view->container, xsurface->fullscreen);

	arrange_root();
	transaction_commit_dirty();
}