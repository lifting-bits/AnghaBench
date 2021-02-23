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
typedef  int /*<<< orphan*/  Manager ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ *) ; 
 int manager_dns_stub_start (int /*<<< orphan*/ *) ; 

int manager_start(Manager *m) {
        int r;

        assert(m);

        r = manager_dns_stub_start(m);
        if (r < 0)
                return r;

        return 0;
}