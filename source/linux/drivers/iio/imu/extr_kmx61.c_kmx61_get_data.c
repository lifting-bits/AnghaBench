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
struct kmx61_data {int dummy; } ;
struct iio_dev {int dummy; } ;

/* Variables and functions */
 scalar_t__ iio_priv (struct iio_dev*) ; 

__attribute__((used)) static struct kmx61_data *kmx61_get_data(struct iio_dev *indio_dev)
{
	return *(struct kmx61_data **)iio_priv(indio_dev);
}