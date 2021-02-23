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
 int /*<<< orphan*/  SCHED_RR ; 
 int sched_get_priority_max (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool sched_priority_is_valid(int i) {
        return i >= 0 && i <= sched_get_priority_max(SCHED_RR);
}