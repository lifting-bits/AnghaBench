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
struct ath10k {int monitor_started; int /*<<< orphan*/  conf_mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATH10K_DBG_MAC ; 
 int /*<<< orphan*/  ath10k_dbg (struct ath10k*,int /*<<< orphan*/ ,char*) ; 
 int ath10k_monitor_vdev_delete (struct ath10k*) ; 
 int ath10k_monitor_vdev_stop (struct ath10k*) ; 
 int /*<<< orphan*/  ath10k_warn (struct ath10k*,char*,int) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ath10k_monitor_stop(struct ath10k *ar)
{
	int ret;

	lockdep_assert_held(&ar->conf_mutex);

	ret = ath10k_monitor_vdev_stop(ar);
	if (ret) {
		ath10k_warn(ar, "failed to stop monitor vdev: %d\n", ret);
		return ret;
	}

	ret = ath10k_monitor_vdev_delete(ar);
	if (ret) {
		ath10k_warn(ar, "failed to delete monitor vdev: %d\n", ret);
		return ret;
	}

	ar->monitor_started = false;
	ath10k_dbg(ar, ATH10K_DBG_MAC, "mac monitor stopped\n");

	return 0;
}