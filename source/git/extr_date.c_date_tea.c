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
struct tm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  date_time (struct tm*,struct tm*,int) ; 
 int /*<<< orphan*/  pending_number (struct tm*,int*) ; 

__attribute__((used)) static void date_tea(struct tm *tm, struct tm *now, int *num)
{
	pending_number(tm, num);
	date_time(tm, now, 17);
}