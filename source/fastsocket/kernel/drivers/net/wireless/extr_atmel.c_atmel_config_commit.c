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

/* Variables and functions */
 int atmel_open (struct net_device*) ; 

__attribute__((used)) static int atmel_config_commit(struct net_device *dev,
			       struct iw_request_info *info,	/* NULL */
			       void *zwrq,			/* NULL */
			       char *extra)			/* NULL */
{
	return atmel_open(dev);
}