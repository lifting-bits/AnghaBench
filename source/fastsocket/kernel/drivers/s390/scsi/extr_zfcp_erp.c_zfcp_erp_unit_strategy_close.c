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
struct zfcp_erp_action {int /*<<< orphan*/  step; } ;

/* Variables and functions */
 int ENOMEM ; 
 int ZFCP_ERP_CONTINUES ; 
 int ZFCP_ERP_FAILED ; 
 int ZFCP_ERP_NOMEM ; 
 int /*<<< orphan*/  ZFCP_ERP_STEP_UNIT_CLOSING ; 
 int zfcp_fsf_close_unit (struct zfcp_erp_action*) ; 

__attribute__((used)) static int zfcp_erp_unit_strategy_close(struct zfcp_erp_action *erp_action)
{
	int retval = zfcp_fsf_close_unit(erp_action);
	if (retval == -ENOMEM)
		return ZFCP_ERP_NOMEM;
	erp_action->step = ZFCP_ERP_STEP_UNIT_CLOSING;
	if (retval)
		return ZFCP_ERP_FAILED;
	return ZFCP_ERP_CONTINUES;
}