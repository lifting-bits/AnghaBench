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
struct mp_filter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  filter_wakeup (struct mp_filter*,int) ; 

void mp_filter_mark_async_progress(struct mp_filter *f)
{
    filter_wakeup(f, true);
}