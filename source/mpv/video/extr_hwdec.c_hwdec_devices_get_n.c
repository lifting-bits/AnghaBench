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
struct mp_hwdec_devices {int num_hwctxs; int /*<<< orphan*/  lock; struct mp_hwdec_ctx** hwctxs; } ;
struct mp_hwdec_ctx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

struct mp_hwdec_ctx *hwdec_devices_get_n(struct mp_hwdec_devices *devs, int n)
{
    pthread_mutex_lock(&devs->lock);
    struct mp_hwdec_ctx *res = n < devs->num_hwctxs ? devs->hwctxs[n] : NULL;
    pthread_mutex_unlock(&devs->lock);
    return res;
}