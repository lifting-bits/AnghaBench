#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ sysfd; } ;

/* Variables and functions */
 int /*<<< orphan*/  close (scalar_t__) ; 
 TYPE_1__ state ; 

__attribute__((used)) static void bench_uninit(void)
{
#if CONFIG_LINUX_PERF
    if (state.sysfd > 0)
        close(state.sysfd);
#endif
}