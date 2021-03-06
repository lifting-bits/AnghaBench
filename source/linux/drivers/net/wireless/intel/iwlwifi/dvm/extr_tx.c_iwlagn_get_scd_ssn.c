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
typedef  int u32 ;
struct iwlagn_tx_resp {int frame_count; int /*<<< orphan*/  status; } ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 int IEEE80211_MAX_SN ; 
 int le32_to_cpup (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline u32 iwlagn_get_scd_ssn(struct iwlagn_tx_resp *tx_resp)
{
	return le32_to_cpup((__le32 *)&tx_resp->status +
			    tx_resp->frame_count) & IEEE80211_MAX_SN;
}