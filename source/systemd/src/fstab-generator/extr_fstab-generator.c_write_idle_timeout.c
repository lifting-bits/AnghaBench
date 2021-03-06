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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int write_timeout (int /*<<< orphan*/ *,char const*,char const*,char*,char*) ; 

__attribute__((used)) static int write_idle_timeout(FILE *f, const char *where, const char *opts) {
        return write_timeout(f, where, opts,
                             "x-systemd.idle-timeout\0", "TimeoutIdleSec");
}