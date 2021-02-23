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
struct sir_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SIRDEV_STATE_SET_SPEED ; 
 int sirdev_schedule_request (struct sir_dev*,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static inline int sirdev_schedule_speed(struct sir_dev *dev, unsigned speed)
{
	return sirdev_schedule_request(dev, SIRDEV_STATE_SET_SPEED, speed);
}