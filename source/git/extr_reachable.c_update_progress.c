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
struct connectivity_progress {int count; int /*<<< orphan*/  progress; } ;

/* Variables and functions */
 int /*<<< orphan*/  display_progress (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void update_progress(struct connectivity_progress *cp)
{
	cp->count++;
	if ((cp->count & 1023) == 0)
		display_progress(cp->progress, cp->count);
}