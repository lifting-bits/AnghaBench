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
struct device {scalar_t__ bus; } ;
struct count_children {scalar_t__ bus; scalar_t__ n; } ;

/* Variables and functions */
 int EBUSY ; 

__attribute__((used)) static int maybe_count_child(struct device *dev, void *c)
{
	struct count_children *ccp = c;

	if (dev->bus == ccp->bus) {
		if (ccp->n)
			return -EBUSY;
		ccp->n++;
	}
	return 0;
}