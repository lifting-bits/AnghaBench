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
typedef  int u64 ;
struct hci_dev {int le_adv_min_interval; int le_adv_max_interval; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  hci_dev_lock (struct hci_dev*) ; 
 int /*<<< orphan*/  hci_dev_unlock (struct hci_dev*) ; 

__attribute__((used)) static int adv_max_interval_set(void *data, u64 val)
{
	struct hci_dev *hdev = data;

	if (val < 0x0020 || val > 0x4000 || val < hdev->le_adv_min_interval)
		return -EINVAL;

	hci_dev_lock(hdev);
	hdev->le_adv_max_interval = val;
	hci_dev_unlock(hdev);

	return 0;
}