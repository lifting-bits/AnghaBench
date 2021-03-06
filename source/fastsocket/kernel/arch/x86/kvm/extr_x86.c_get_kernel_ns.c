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
typedef  int /*<<< orphan*/  u64 ;
struct timespec {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_get_ts (struct timespec*) ; 
 int /*<<< orphan*/  monotonic_to_bootbased (struct timespec*) ; 
 int /*<<< orphan*/  preemptible () ; 
 int /*<<< orphan*/  timespec_to_ns (struct timespec*) ; 

__attribute__((used)) static inline u64 get_kernel_ns(void)
{
	struct timespec ts;

	WARN_ON(preemptible());
	ktime_get_ts(&ts);
	monotonic_to_bootbased(&ts);
	return timespec_to_ns(&ts);
}