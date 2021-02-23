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
 int /*<<< orphan*/  die (int,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  errno ; 
 int fileno (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * tmpfile () ; 

__attribute__((used)) static int
tmpfd(void)
{
    FILE *f = tmpfile();
    if (!f) {
        die(1, errno, "tmpfile");
    }
    return fileno(f);
}