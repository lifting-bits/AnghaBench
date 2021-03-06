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
struct usb_interface {int /*<<< orphan*/  dev; } ;
struct i2c_diolan_u2c {int /*<<< orphan*/  adapter; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  diolan_u2c_free (struct i2c_diolan_u2c*) ; 
 int /*<<< orphan*/  i2c_del_adapter (int /*<<< orphan*/ *) ; 
 struct i2c_diolan_u2c* usb_get_intfdata (struct usb_interface*) ; 
 int /*<<< orphan*/  usb_set_intfdata (struct usb_interface*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void diolan_u2c_disconnect(struct usb_interface *interface)
{
	struct i2c_diolan_u2c *dev = usb_get_intfdata(interface);

	i2c_del_adapter(&dev->adapter);
	usb_set_intfdata(interface, NULL);
	diolan_u2c_free(dev);

	dev_dbg(&interface->dev, "disconnected\n");
}