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
typedef  int /*<<< orphan*/  zdev_t ;
typedef  int /*<<< orphan*/  u32_t ;
typedef  int /*<<< orphan*/  u16_t ;

/* Variables and functions */
 int /*<<< orphan*/  USB_ENDPOINT_CMD_INDEX ; 
 int /*<<< orphan*/  zfwUsbCmd (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void zfIdlCmd(zdev_t* dev, u32_t* cmd, u16_t cmdLen)
{
#if ZM_SW_LOOP_BACK != 1
    zfwUsbCmd(dev, USB_ENDPOINT_CMD_INDEX, cmd, cmdLen);
#endif

    return;
}