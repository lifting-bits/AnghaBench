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
struct TYPE_2__ {int /*<<< orphan*/  pd; int /*<<< orphan*/  cq; int /*<<< orphan*/  qp; } ;
struct mlx5_ib_dev {TYPE_1__ umrc; } ;

/* Variables and functions */
 int /*<<< orphan*/  ib_dealloc_pd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ib_free_cq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx5_ib_destroy_qp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx5_ib_warn (struct mlx5_ib_dev*,char*) ; 
 int mlx5_mr_cache_cleanup (struct mlx5_ib_dev*) ; 

__attribute__((used)) static void destroy_umrc_res(struct mlx5_ib_dev *dev)
{
	int err;

	err = mlx5_mr_cache_cleanup(dev);
	if (err)
		mlx5_ib_warn(dev, "mr cache cleanup failed\n");

	mlx5_ib_destroy_qp(dev->umrc.qp);
	ib_free_cq(dev->umrc.cq);
	ib_dealloc_pd(dev->umrc.pd);
}