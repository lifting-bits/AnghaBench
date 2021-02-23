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
struct mlx5_core_dev {int dummy; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  MLX5_SEMAPHORE_SW_RESET ; 
 int /*<<< orphan*/  mlx5_core_dbg (struct mlx5_core_dev*,char*) ; 
 int /*<<< orphan*/  mlx5_core_warn (struct mlx5_core_dev*,char*,int) ; 
 int mlx5_vsc_lock (struct mlx5_core_dev*) ; 
 int mlx5_vsc_lock_addr_space (struct mlx5_core_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx5_vsc_unlock (struct mlx5_core_dev*) ; 

__attribute__((used)) static int lock_sem_sw_reset(struct mlx5_core_dev *dev)
{
	int ret;

	/* Lock GW access */
	ret = -mlx5_vsc_lock(dev);
	if (ret) {
		mlx5_core_warn(dev, "Timed out locking gateway %d\n", ret);
		return ret;
	}

	ret = -mlx5_vsc_lock_addr_space(dev, MLX5_SEMAPHORE_SW_RESET);
	if (ret) {
		if (ret == -EBUSY)
			mlx5_core_dbg(dev,
			    "SW reset FW semaphore already locked, another function will handle the reset\n");
		else
			mlx5_core_warn(dev,
			    "SW reset semaphore lock return %d\n", ret);
	}

	/* Unlock GW access */
	mlx5_vsc_unlock(dev);

	return ret;
}