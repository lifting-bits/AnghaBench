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
struct device {int dummy; } ;

/* Variables and functions */
 int ccdc_restore_defaults () ; 
 struct device* dev ; 

__attribute__((used)) static int ccdc_open(struct device *device)
{
	dev = device;
	return ccdc_restore_defaults();
}