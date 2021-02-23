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
struct rtc_device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 struct rtc_device* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  isl1208_sysfs_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rtc_device_unregister (struct rtc_device*) ; 

__attribute__((used)) static int
isl1208_remove(struct i2c_client *client)
{
	struct rtc_device *rtc = i2c_get_clientdata(client);

	isl1208_sysfs_unregister(&client->dev);
	rtc_device_unregister(rtc);

	return 0;
}