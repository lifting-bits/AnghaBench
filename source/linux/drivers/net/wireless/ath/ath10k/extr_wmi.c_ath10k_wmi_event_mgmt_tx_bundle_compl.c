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
typedef  int u32 ;
struct wmi_tlv_mgmt_tx_bundle_compl_ev_arg {int /*<<< orphan*/ * ack_rssi; int /*<<< orphan*/ * desc_ids; int /*<<< orphan*/  num_reports; } ;
struct sk_buff {int dummy; } ;
struct mgmt_tx_compl_params {void* ack_rssi; void* status; void* desc_id; } ;
struct TYPE_2__ {int /*<<< orphan*/  svc_map; } ;
struct ath10k {TYPE_1__ wmi; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATH10K_DBG_WMI ; 
 int /*<<< orphan*/  WMI_SERVICE_TX_DATA_ACK_RSSI ; 
 void* __le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath10k_dbg (struct ath10k*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ath10k_warn (struct ath10k*,char*,int) ; 
 int ath10k_wmi_pull_mgmt_tx_bundle_compl (struct ath10k*,struct sk_buff*,struct wmi_tlv_mgmt_tx_bundle_compl_ev_arg*) ; 
 int /*<<< orphan*/  memset (struct mgmt_tx_compl_params*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wmi_process_mgmt_tx_comp (struct ath10k*,struct mgmt_tx_compl_params*) ; 

int ath10k_wmi_event_mgmt_tx_bundle_compl(struct ath10k *ar, struct sk_buff *skb)
{
	struct wmi_tlv_mgmt_tx_bundle_compl_ev_arg arg;
	struct mgmt_tx_compl_params param;
	u32 num_reports;
	int i, ret;

	ret = ath10k_wmi_pull_mgmt_tx_bundle_compl(ar, skb, &arg);
	if (ret) {
		ath10k_warn(ar, "failed to parse bundle mgmt compl event: %d\n", ret);
		return ret;
	}

	num_reports = __le32_to_cpu(arg.num_reports);

	for (i = 0; i < num_reports; i++) {
		memset(&param, 0, sizeof(struct mgmt_tx_compl_params));
		param.desc_id = __le32_to_cpu(arg.desc_ids[i]);
		param.status = __le32_to_cpu(arg.desc_ids[i]);

		if (test_bit(WMI_SERVICE_TX_DATA_ACK_RSSI, ar->wmi.svc_map))
			param.ack_rssi = __le32_to_cpu(arg.ack_rssi[i]);
		wmi_process_mgmt_tx_comp(ar, &param);
	}

	ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv event bundle mgmt tx completion\n");

	return 0;
}