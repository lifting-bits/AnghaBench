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
struct mlx5_ib_qp {int /*<<< orphan*/  buf; } ;

/* Variables and functions */
 void* mlx5_buf_offset (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void *get_wqe(struct mlx5_ib_qp *qp, int offset)
{
	return mlx5_buf_offset(&qp->buf, offset);
}