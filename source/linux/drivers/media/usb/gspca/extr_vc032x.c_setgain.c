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
typedef  int /*<<< orphan*/  u8 ;
struct gspca_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  i2c_write (struct gspca_dev*,int,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void setgain(struct gspca_dev *gspca_dev, u8 val)
{
	i2c_write(gspca_dev, 0x15, &val, 1);
}