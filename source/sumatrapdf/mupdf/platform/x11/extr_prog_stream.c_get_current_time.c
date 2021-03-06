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
struct timeval {int tv_usec; scalar_t__ tv_sec; } ;
typedef  int int64_t ;

/* Variables and functions */
 scalar_t__ GetTickCount () ; 
 int /*<<< orphan*/  gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int64_t get_current_time(void)
{
#ifdef _WIN32
	return (int)GetTickCount();
#else
	struct timeval now;
	gettimeofday(&now, NULL);
	return (int64_t)now.tv_sec*1000 + now.tv_usec/1000;
#endif
}