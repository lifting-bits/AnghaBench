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
typedef  int /*<<< orphan*/  AVFilterContext ;

/* Variables and functions */
 int filter_slice_rgba16_packed (int /*<<< orphan*/ *,void*,int,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int filter_slice_rgb48(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs)
{
    return filter_slice_rgba16_packed(ctx, arg, jobnr, nb_jobs, 0, 3);
}