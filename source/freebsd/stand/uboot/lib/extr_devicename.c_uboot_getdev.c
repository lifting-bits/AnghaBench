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
struct uboot_devdesc {int dummy; } ;

/* Variables and functions */
 char const* getenv (char*) ; 
 int /*<<< orphan*/ * strchr (char const*,char) ; 
 int uboot_parsedev (struct uboot_devdesc**,char const*,char const**) ; 

int
uboot_getdev(void **vdev, const char *devspec, const char **path)
{
	struct uboot_devdesc **dev = (struct uboot_devdesc **)vdev;
	int rv;

	/*
	 * If it looks like this is just a path and no
	 * device, go with the current device.
	 */
	if ((devspec == NULL) || (devspec[0] == '/') ||
	    (strchr(devspec, ':') == NULL)) {

		if (((rv = uboot_parsedev(dev, getenv("currdev"), NULL)) == 0)
		    && (path != NULL))
		*path = devspec;
		return(rv);
	}

	/*
	 * Try to parse the device name off the beginning of the devspec.
	 */
	return (uboot_parsedev(dev, devspec, path));
}