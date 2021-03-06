#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  index; } ;
typedef  TYPE_2__ cvmx_usbd_state_t ;
typedef  int /*<<< orphan*/  cvmx_usbd_speed_t ;
struct TYPE_7__ {int /*<<< orphan*/  devspd; } ;
struct TYPE_9__ {int /*<<< orphan*/  u32; TYPE_1__ s; } ;
typedef  TYPE_3__ cvmx_usbcx_dcfg_t ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_USBCX_DCFG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __cvmx_usbd_read_csr32 (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __cvmx_usbd_write_csr32 (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void cvmx_usbd_set_speed(cvmx_usbd_state_t *usb, cvmx_usbd_speed_t speed)
{
    cvmx_usbcx_dcfg_t usbcx_dcfg;
    usbcx_dcfg.u32 = __cvmx_usbd_read_csr32(usb, CVMX_USBCX_DCFG(usb->index));
    usbcx_dcfg.s.devspd = speed;
    __cvmx_usbd_write_csr32(usb, CVMX_USBCX_DCFG(usb->index), usbcx_dcfg.u32);
}