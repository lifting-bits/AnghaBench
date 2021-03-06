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
typedef  int /*<<< orphan*/  u32 ;
struct ecore_resc_alloc_out_params {int res_id; int /*<<< orphan*/  mcp_resp; int /*<<< orphan*/  resc_max_val; int /*<<< orphan*/  cmd; } ;
struct ecore_resc_alloc_in_params {int res_id; int /*<<< orphan*/  mcp_resp; int /*<<< orphan*/  resc_max_val; int /*<<< orphan*/  cmd; } ;
struct ecore_ptt {int dummy; } ;
struct ecore_hwfn {int dummy; } ;
typedef  int /*<<< orphan*/  out_params ;
typedef  int /*<<< orphan*/  in_params ;
typedef  enum ecore_resources { ____Placeholder_ecore_resources } ecore_resources ;
typedef  enum _ecore_status_t { ____Placeholder__ecore_status_t } _ecore_status_t ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_MSG_SET_RESOURCE_VALUE_MSG ; 
 int ECORE_SUCCESS ; 
 int /*<<< orphan*/  OSAL_MEM_ZERO (struct ecore_resc_alloc_out_params*,int) ; 
 int ecore_mcp_resc_allocation_msg (struct ecore_hwfn*,struct ecore_ptt*,struct ecore_resc_alloc_out_params*,struct ecore_resc_alloc_out_params*) ; 

enum _ecore_status_t
ecore_mcp_set_resc_max_val(struct ecore_hwfn *p_hwfn, struct ecore_ptt *p_ptt,
			   enum ecore_resources res_id, u32 resc_max_val,
			   u32 *p_mcp_resp)
{
	struct ecore_resc_alloc_out_params out_params;
	struct ecore_resc_alloc_in_params in_params;
	enum _ecore_status_t rc;

	OSAL_MEM_ZERO(&in_params, sizeof(in_params));
	in_params.cmd = DRV_MSG_SET_RESOURCE_VALUE_MSG;
	in_params.res_id = res_id;
	in_params.resc_max_val = resc_max_val;
	OSAL_MEM_ZERO(&out_params, sizeof(out_params));
	rc = ecore_mcp_resc_allocation_msg(p_hwfn, p_ptt, &in_params,
					   &out_params);
	if (rc != ECORE_SUCCESS)
		return rc;

	*p_mcp_resp = out_params.mcp_resp;

	return ECORE_SUCCESS;
}