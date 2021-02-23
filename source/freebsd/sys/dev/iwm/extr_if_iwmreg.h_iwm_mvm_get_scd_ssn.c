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
typedef  int uint32_t ;
struct iwm_mvm_tx_resp {int frame_count; int /*<<< orphan*/  status; } ;

/* Variables and functions */
 int le32_to_cpup (int*) ; 

__attribute__((used)) static inline uint32_t iwm_mvm_get_scd_ssn(struct iwm_mvm_tx_resp *tx_resp)
{
	return le32_to_cpup((uint32_t *)&tx_resp->status +
			    tx_resp->frame_count) & 0xfff;
}