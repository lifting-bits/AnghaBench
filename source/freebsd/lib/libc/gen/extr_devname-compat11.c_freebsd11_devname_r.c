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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  mode_t ;

/* Variables and functions */
 char* devname_r (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int) ; 

char *
freebsd11_devname_r(uint32_t dev, mode_t type, char *buf, int len)
{

	return (devname_r(dev, type, buf, len));
}