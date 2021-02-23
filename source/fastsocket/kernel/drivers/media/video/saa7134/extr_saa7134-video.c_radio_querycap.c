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
struct v4l2_capability {int /*<<< orphan*/  capabilities; int /*<<< orphan*/  version; int /*<<< orphan*/  bus_info; int /*<<< orphan*/  card; int /*<<< orphan*/  driver; } ;
struct saa7134_fh {struct saa7134_dev* dev; } ;
struct saa7134_dev {size_t board; int /*<<< orphan*/  pci; } ;
struct file {struct saa7134_fh* private_data; } ;
struct TYPE_2__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  SAA7134_VERSION_CODE ; 
 int /*<<< orphan*/  V4L2_CAP_TUNER ; 
 char* pci_name (int /*<<< orphan*/ ) ; 
 TYPE_1__* saa7134_boards ; 
 int /*<<< orphan*/  sprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int radio_querycap(struct file *file, void *priv,
					struct v4l2_capability *cap)
{
	struct saa7134_fh *fh = file->private_data;
	struct saa7134_dev *dev = fh->dev;

	strcpy(cap->driver, "saa7134");
	strlcpy(cap->card, saa7134_boards[dev->board].name, sizeof(cap->card));
	sprintf(cap->bus_info, "PCI:%s", pci_name(dev->pci));
	cap->version = SAA7134_VERSION_CODE;
	cap->capabilities = V4L2_CAP_TUNER;
	return 0;
}