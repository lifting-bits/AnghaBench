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
struct soc_camera_host {struct mx1_camera_dev* priv; } ;
struct TYPE_2__ {int /*<<< orphan*/  parent; } ;
struct soc_camera_device {int /*<<< orphan*/  devnum; TYPE_1__ dev; } ;
struct mx1_camera_dev {struct soc_camera_device* icd; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mx1_camera_activate (struct mx1_camera_dev*) ; 
 struct soc_camera_host* to_soc_camera_host (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mx1_camera_add_device(struct soc_camera_device *icd)
{
	struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
	struct mx1_camera_dev *pcdev = ici->priv;
	int ret;

	if (pcdev->icd) {
		ret = -EBUSY;
		goto ebusy;
	}

	dev_info(icd->dev.parent, "MX1 Camera driver attached to camera %d\n",
		 icd->devnum);

	mx1_camera_activate(pcdev);

	pcdev->icd = icd;

ebusy:
	return ret;
}