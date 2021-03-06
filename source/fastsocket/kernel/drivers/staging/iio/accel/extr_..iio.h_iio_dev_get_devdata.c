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
struct iio_dev {void* dev_data; } ;

/* Variables and functions */

__attribute__((used)) static inline void *iio_dev_get_devdata(struct iio_dev *d)
{
	return d->dev_data;
}