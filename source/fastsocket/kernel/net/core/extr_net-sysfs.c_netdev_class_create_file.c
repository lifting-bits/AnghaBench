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
struct class_attribute {int dummy; } ;

/* Variables and functions */
 int class_create_file (int /*<<< orphan*/ *,struct class_attribute*) ; 
 int /*<<< orphan*/  net_class ; 

int netdev_class_create_file(struct class_attribute *class_attr)
{
	return class_create_file(&net_class, class_attr);
}