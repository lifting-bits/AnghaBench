#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct xenbus_transaction {int dummy; } ;
struct pcistub_device {TYPE_1__* dev; TYPE_2__* pdev; } ;
struct TYPE_6__ {int otherend_id; } ;
struct TYPE_5__ {TYPE_3__* xdev; } ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EAGAIN ; 
 int PCI_NODENAME_MAX ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 int /*<<< orphan*/  xenbus_printf (struct xenbus_transaction,char*,char*,char*) ; 
 int xenbus_transaction_end (struct xenbus_transaction,int /*<<< orphan*/ ) ; 
 int xenbus_transaction_start (struct xenbus_transaction*) ; 

__attribute__((used)) static void kill_domain_by_device(struct pcistub_device *psdev)
{
	struct xenbus_transaction xbt;
	int err;
	char nodename[PCI_NODENAME_MAX];

	BUG_ON(!psdev);
	snprintf(nodename, PCI_NODENAME_MAX, "/local/domain/0/backend/pci/%d/0",
		psdev->pdev->xdev->otherend_id);

again:
	err = xenbus_transaction_start(&xbt);
	if (err) {
		dev_err(&psdev->dev->dev,
			"error %d when start xenbus transaction\n", err);
		return;
	}
	/*PV AER handlers will set this flag*/
	xenbus_printf(xbt, nodename, "aerState" , "aerfail");
	err = xenbus_transaction_end(xbt, 0);
	if (err) {
		if (err == -EAGAIN)
			goto again;
		dev_err(&psdev->dev->dev,
			"error %d when end xenbus transaction\n", err);
		return;
	}
}