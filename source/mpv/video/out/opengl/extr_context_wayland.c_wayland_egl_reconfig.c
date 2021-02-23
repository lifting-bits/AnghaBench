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
struct ra_ctx {int /*<<< orphan*/  vo; struct priv* priv; } ;
struct priv {int /*<<< orphan*/  egl_window; } ;

/* Variables and functions */
 int /*<<< orphan*/  egl_create_window (struct ra_ctx*) ; 
 int /*<<< orphan*/  vo_wayland_reconfig (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool wayland_egl_reconfig(struct ra_ctx *ctx)
{
    struct priv *p = ctx->priv;

    if (!vo_wayland_reconfig(ctx->vo))
        return false;

    if (!p->egl_window)
        egl_create_window(ctx);

    return true;
}