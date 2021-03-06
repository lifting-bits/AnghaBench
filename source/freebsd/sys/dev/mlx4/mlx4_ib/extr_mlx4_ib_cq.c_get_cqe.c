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
struct mlx4_ib_cq {int /*<<< orphan*/  buf; } ;

/* Variables and functions */
 void* get_cqe_from_buf (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void *get_cqe(struct mlx4_ib_cq *cq, int n)
{
	return get_cqe_from_buf(&cq->buf, n);
}