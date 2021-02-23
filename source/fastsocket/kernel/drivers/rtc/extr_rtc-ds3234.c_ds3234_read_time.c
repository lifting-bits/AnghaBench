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
struct spi_device {int dummy; } ;
struct rtc_time {void* tm_year; void* tm_mon; void* tm_mday; void* tm_wday; void* tm_hour; void* tm_min; void* tm_sec; } ;
struct device {int dummy; } ;

/* Variables and functions */
 void* bcd2bin (unsigned char) ; 
 int rtc_valid_tm (struct rtc_time*) ; 
 int spi_write_then_read (struct spi_device*,unsigned char*,int,unsigned char*,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int ds3234_read_time(struct device *dev, struct rtc_time *dt)
{
	int err;
	unsigned char buf[8];
	struct spi_device *spi = to_spi_device(dev);

	buf[0] = 0x00; /* Start address */

	err = spi_write_then_read(spi, buf, 1, buf, 8);
	if (err != 0)
		return err;

	/* Seconds, Minutes, Hours, Day, Date, Month, Year */
	dt->tm_sec	= bcd2bin(buf[0]);
	dt->tm_min	= bcd2bin(buf[1]);
	dt->tm_hour	= bcd2bin(buf[2] & 0x3f);
	dt->tm_wday	= bcd2bin(buf[3]) - 1; /* 0 = Sun */
	dt->tm_mday	= bcd2bin(buf[4]);
	dt->tm_mon	= bcd2bin(buf[5] & 0x1f) - 1; /* 0 = Jan */
	dt->tm_year 	= bcd2bin(buf[6] & 0xff) + 100; /* Assume 20YY */

	return rtc_valid_tm(dt);
}