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
struct net_device {int dummy; } ;
struct iw_request_info {int dummy; } ;
struct iw_param {int dummy; } ;

/* Variables and functions */

int usbdrvwext_siwsens(struct net_device *dev,
			struct iw_request_info *info,
			struct iw_param *sens, char *extra)
{
	return 0;
}