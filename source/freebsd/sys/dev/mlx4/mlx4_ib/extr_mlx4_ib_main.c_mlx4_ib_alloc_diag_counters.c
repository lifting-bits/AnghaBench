#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct mlx4_ib_diag_counters {int /*<<< orphan*/  offset; int /*<<< orphan*/  name; int /*<<< orphan*/  num_counters; } ;
struct TYPE_5__ {int /*<<< orphan*/  alloc_hw_stats; int /*<<< orphan*/  get_hw_stats; } ;
struct mlx4_ib_dev {TYPE_2__ ib_dev; TYPE_3__* dev; struct mlx4_ib_diag_counters* diag_counters; } ;
struct TYPE_4__ {int flags2; } ;
struct TYPE_6__ {TYPE_1__ caps; } ;

/* Variables and functions */
 int MLX4_DEV_CAP_FLAG2_DIAG_PER_PORT ; 
 int MLX4_DIAG_COUNTERS_TYPES ; 
 int __mlx4_ib_alloc_diag_counters (struct mlx4_ib_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx4_ib_alloc_hw_stats ; 
 int /*<<< orphan*/  mlx4_ib_fill_diag_counters (struct mlx4_ib_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mlx4_ib_get_hw_stats ; 
 scalar_t__ mlx4_is_slave (TYPE_3__*) ; 

__attribute__((used)) static int mlx4_ib_alloc_diag_counters(struct mlx4_ib_dev *ibdev)
{
	struct mlx4_ib_diag_counters *diag = ibdev->diag_counters;
	int i;
	int ret;
	bool per_port = !!(ibdev->dev->caps.flags2 &
		MLX4_DEV_CAP_FLAG2_DIAG_PER_PORT);

	if (mlx4_is_slave(ibdev->dev))
		return 0;

	for (i = 0; i < MLX4_DIAG_COUNTERS_TYPES; i++) {
		/* i == 1 means we are building port counters */
		if (i && !per_port)
			continue;

		ret = __mlx4_ib_alloc_diag_counters(ibdev, &diag[i].name,
						    &diag[i].offset,
						    &diag[i].num_counters, i);
		if (ret)
			goto err_alloc;

		mlx4_ib_fill_diag_counters(ibdev, diag[i].name,
					   diag[i].offset, i);
	}

	ibdev->ib_dev.get_hw_stats	= mlx4_ib_get_hw_stats;
	ibdev->ib_dev.alloc_hw_stats	= mlx4_ib_alloc_hw_stats;

	return 0;

err_alloc:
	if (i) {
		kfree(diag[i - 1].name);
		kfree(diag[i - 1].offset);
	}

	return ret;
}