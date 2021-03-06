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
struct mlxsw_sp_acl_tcam_mr_ruleset {int /*<<< orphan*/  vgroup; int /*<<< orphan*/  vchunk; } ;
struct mlxsw_sp {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_sp_acl_tcam_vchunk_put (struct mlxsw_sp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_sp_acl_tcam_vgroup_del (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
mlxsw_sp_acl_tcam_mr_ruleset_del(struct mlxsw_sp *mlxsw_sp, void *ruleset_priv)
{
	struct mlxsw_sp_acl_tcam_mr_ruleset *ruleset = ruleset_priv;

	mlxsw_sp_acl_tcam_vchunk_put(mlxsw_sp, ruleset->vchunk);
	mlxsw_sp_acl_tcam_vgroup_del(&ruleset->vgroup);
}