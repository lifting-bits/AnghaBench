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

/* Variables and functions */
 int /*<<< orphan*/  warnx (char*,char*) ; 

__attribute__((used)) static void
dowarn(int line)
{

	warnx("warning: can't back up %s",
		line < 0 ? "past first line" : "-- line already flushed");
}