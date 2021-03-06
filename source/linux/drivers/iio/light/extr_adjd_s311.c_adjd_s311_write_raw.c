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
struct iio_dev {int dummy; } ;
struct iio_chan_spec {int /*<<< orphan*/  address; } ;
struct adjd_s311_data {int /*<<< orphan*/  client; } ;

/* Variables and functions */
 int ADJD_S311_CAP_MASK ; 
 int /*<<< orphan*/  ADJD_S311_CAP_REG (int /*<<< orphan*/ ) ; 
 int ADJD_S311_INT_MASK ; 
 int /*<<< orphan*/  ADJD_S311_INT_REG (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
#define  IIO_CHAN_INFO_HARDWAREGAIN 129 
#define  IIO_CHAN_INFO_INT_TIME 128 
 int i2c_smbus_write_byte_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_write_word_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct adjd_s311_data* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static int adjd_s311_write_raw(struct iio_dev *indio_dev,
			       struct iio_chan_spec const *chan,
			       int val, int val2, long mask)
{
	struct adjd_s311_data *data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_HARDWAREGAIN:
		if (val < 0 || val > ADJD_S311_CAP_MASK)
			return -EINVAL;

		return i2c_smbus_write_byte_data(data->client,
			ADJD_S311_CAP_REG(chan->address), val);
	case IIO_CHAN_INFO_INT_TIME:
		if (val != 0 || val2 < 0 || val2 > ADJD_S311_INT_MASK)
			return -EINVAL;

		return i2c_smbus_write_word_data(data->client,
			ADJD_S311_INT_REG(chan->address), val2);
	}
	return -EINVAL;
}