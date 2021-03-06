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
struct hci_dev {scalar_t__ driver_data; } ;
struct TYPE_2__ {int /*<<< orphan*/  txq; } ;
typedef  TYPE_1__ dtl1_info_t ;

/* Variables and functions */
 int /*<<< orphan*/  skb_queue_purge (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int dtl1_hci_flush(struct hci_dev *hdev)
{
	dtl1_info_t *info = (dtl1_info_t *)(hdev->driver_data);

	/* Drop TX queue */
	skb_queue_purge(&(info->txq));

	return 0;
}