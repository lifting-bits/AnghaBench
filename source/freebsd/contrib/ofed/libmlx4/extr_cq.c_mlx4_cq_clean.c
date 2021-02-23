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
typedef  int /*<<< orphan*/  uint32_t ;
struct mlx4_srq {int dummy; } ;
struct mlx4_cq {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  __mlx4_cq_clean (struct mlx4_cq*,int /*<<< orphan*/ ,struct mlx4_srq*) ; 
 int /*<<< orphan*/  pthread_spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_spin_unlock (int /*<<< orphan*/ *) ; 

void mlx4_cq_clean(struct mlx4_cq *cq, uint32_t qpn, struct mlx4_srq *srq)
{
	pthread_spin_lock(&cq->lock);
	__mlx4_cq_clean(cq, qpn, srq);
	pthread_spin_unlock(&cq->lock);
}