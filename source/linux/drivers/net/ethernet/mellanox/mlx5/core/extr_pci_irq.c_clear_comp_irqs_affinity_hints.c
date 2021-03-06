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
struct TYPE_2__ {int /*<<< orphan*/  irq_table; } ;
struct mlx5_core_dev {TYPE_1__ priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  clear_comp_irq_affinity_hint (struct mlx5_core_dev*,int) ; 
 int mlx5_irq_get_num_comp (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void clear_comp_irqs_affinity_hints(struct mlx5_core_dev *mdev)
{
	int nvec = mlx5_irq_get_num_comp(mdev->priv.irq_table);
	int i;

	for (i = 0; i < nvec; i++)
		clear_comp_irq_affinity_hint(mdev, i);
}