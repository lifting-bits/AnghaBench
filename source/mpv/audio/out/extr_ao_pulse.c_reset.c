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
struct priv {scalar_t__ retval; int /*<<< orphan*/  stream; int /*<<< orphan*/  mainloop; } ;
struct ao {struct priv* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  GENERIC_ERR_MSG (char*) ; 
 int /*<<< orphan*/  cork (struct ao*,int) ; 
 int /*<<< orphan*/  pa_stream_flush (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ao*) ; 
 int /*<<< orphan*/  pa_threaded_mainloop_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  success_cb ; 
 int /*<<< orphan*/  waitop (struct priv*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void reset(struct ao *ao)
{
    // pa_stream_flush() works badly if not corked
    cork(ao, true);
    struct priv *priv = ao->priv;
    pa_threaded_mainloop_lock(priv->mainloop);
    priv->retval = 0;
    if (!waitop(priv, pa_stream_flush(priv->stream, success_cb, ao)) ||
        !priv->retval)
        GENERIC_ERR_MSG("pa_stream_flush() failed");
    cork(ao, false);
}