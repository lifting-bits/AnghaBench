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
struct mlx5e_sq {int /*<<< orphan*/  sqn; TYPE_1__* priv; } ;
struct TYPE_2__ {int /*<<< orphan*/  mdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlx5_core_destroy_sq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
mlx5e_disable_sq(struct mlx5e_sq *sq)
{

	mlx5_core_destroy_sq(sq->priv->mdev, sq->sqn);
}