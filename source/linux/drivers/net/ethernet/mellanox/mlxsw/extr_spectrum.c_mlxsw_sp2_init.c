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
struct mlxsw_sp {int /*<<< orphan*/ * ptp_ops; int /*<<< orphan*/ * port_type_speed_ops; int /*<<< orphan*/ * sb_vals; int /*<<< orphan*/  rif_ops_arr; int /*<<< orphan*/  mac_mask; int /*<<< orphan*/  nve_ops_arr; int /*<<< orphan*/ * acl_tcam_ops; int /*<<< orphan*/ * mr_tcam_ops; int /*<<< orphan*/ * afk_ops; int /*<<< orphan*/ * afa_ops; int /*<<< orphan*/ * kvdl_ops; } ;
struct mlxsw_core {int dummy; } ;
struct mlxsw_bus_info {int dummy; } ;

/* Variables and functions */
 struct mlxsw_sp* mlxsw_core_driver_priv (struct mlxsw_core*) ; 
 int /*<<< orphan*/  mlxsw_sp2_acl_tcam_ops ; 
 int /*<<< orphan*/  mlxsw_sp2_act_afa_ops ; 
 int /*<<< orphan*/  mlxsw_sp2_afk_ops ; 
 int /*<<< orphan*/  mlxsw_sp2_kvdl_ops ; 
 int /*<<< orphan*/  mlxsw_sp2_mac_mask ; 
 int /*<<< orphan*/  mlxsw_sp2_mr_tcam_ops ; 
 int /*<<< orphan*/  mlxsw_sp2_nve_ops_arr ; 
 int /*<<< orphan*/  mlxsw_sp2_port_type_speed_ops ; 
 int /*<<< orphan*/  mlxsw_sp2_ptp_ops ; 
 int /*<<< orphan*/  mlxsw_sp2_rif_ops_arr ; 
 int /*<<< orphan*/  mlxsw_sp2_sb_vals ; 
 int mlxsw_sp_init (struct mlxsw_core*,struct mlxsw_bus_info const*) ; 

__attribute__((used)) static int mlxsw_sp2_init(struct mlxsw_core *mlxsw_core,
			  const struct mlxsw_bus_info *mlxsw_bus_info)
{
	struct mlxsw_sp *mlxsw_sp = mlxsw_core_driver_priv(mlxsw_core);

	mlxsw_sp->kvdl_ops = &mlxsw_sp2_kvdl_ops;
	mlxsw_sp->afa_ops = &mlxsw_sp2_act_afa_ops;
	mlxsw_sp->afk_ops = &mlxsw_sp2_afk_ops;
	mlxsw_sp->mr_tcam_ops = &mlxsw_sp2_mr_tcam_ops;
	mlxsw_sp->acl_tcam_ops = &mlxsw_sp2_acl_tcam_ops;
	mlxsw_sp->nve_ops_arr = mlxsw_sp2_nve_ops_arr;
	mlxsw_sp->mac_mask = mlxsw_sp2_mac_mask;
	mlxsw_sp->rif_ops_arr = mlxsw_sp2_rif_ops_arr;
	mlxsw_sp->sb_vals = &mlxsw_sp2_sb_vals;
	mlxsw_sp->port_type_speed_ops = &mlxsw_sp2_port_type_speed_ops;
	mlxsw_sp->ptp_ops = &mlxsw_sp2_ptp_ops;

	return mlxsw_sp_init(mlxsw_core, mlxsw_bus_info);
}