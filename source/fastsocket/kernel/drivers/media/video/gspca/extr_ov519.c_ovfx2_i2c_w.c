#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_2__ {int usb_err; int /*<<< orphan*/  dev; } ;
struct sd {TYPE_1__ gspca_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  D_USBO ; 
 int /*<<< orphan*/  PDEBUG (int /*<<< orphan*/ ,char*,scalar_t__,scalar_t__) ; 
 int USB_DIR_OUT ; 
 int USB_RECIP_DEVICE ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  err (char*,scalar_t__,int) ; 
 int usb_control_msg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ovfx2_i2c_w(struct sd *sd, u8 reg, u8 value)
{
	int ret;

	if (sd->gspca_dev.usb_err < 0)
		return;

	ret = usb_control_msg(sd->gspca_dev.dev,
			usb_sndctrlpipe(sd->gspca_dev.dev, 0),
			0x02,
			USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
			(u16) value, (u16) reg, NULL, 0, 500);

	if (ret < 0) {
		err("ovfx2_i2c_w %02x failed %d", reg, ret);
		sd->gspca_dev.usb_err = ret;
	}

	PDEBUG(D_USBO, "ovfx2_i2c_w %02x %02x", reg, value);
}