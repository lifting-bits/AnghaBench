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
typedef  int /*<<< orphan*/  u8 ;

/* Variables and functions */
 int /*<<< orphan*/  MLXSW_REG_PPTB_ALL_PRIO ; 
 int /*<<< orphan*/  MLXSW_REG_PPTB_MM_UM ; 
 int /*<<< orphan*/  MLXSW_REG_ZERO (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mlxsw_reg_pptb_local_port_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_pptb_mm_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_pptb_pm_msb_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_pptb_pm_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pptb ; 

__attribute__((used)) static inline void mlxsw_reg_pptb_pack(char *payload, u8 local_port)
{
	MLXSW_REG_ZERO(pptb, payload);
	mlxsw_reg_pptb_mm_set(payload, MLXSW_REG_PPTB_MM_UM);
	mlxsw_reg_pptb_local_port_set(payload, local_port);
	mlxsw_reg_pptb_pm_set(payload, MLXSW_REG_PPTB_ALL_PRIO);
	mlxsw_reg_pptb_pm_msb_set(payload, MLXSW_REG_PPTB_ALL_PRIO);
}