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
struct mlx5_core_srq {int /*<<< orphan*/  srqn; } ;
struct mlx5_core_dev {int dummy; } ;

/* Variables and functions */
 int mlx5_core_destroy_xsrq (struct mlx5_core_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int destroy_xrc_srq_cmd(struct mlx5_core_dev *dev,
			       struct mlx5_core_srq *srq)
{
	return mlx5_core_destroy_xsrq(dev, srq->srqn);
}