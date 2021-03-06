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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;

/* Variables and functions */
 int DR_STE_ENABLE_FLOW_TAG ; 
 int /*<<< orphan*/  MLX5_SET (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  qp_list_pointer ; 
 int /*<<< orphan*/  ste_rx_steering_mult ; 

void mlx5dr_ste_rx_set_flow_tag(u8 *hw_ste_p, u32 flow_tag)
{
	MLX5_SET(ste_rx_steering_mult, hw_ste_p, qp_list_pointer,
		 DR_STE_ENABLE_FLOW_TAG | flow_tag);
}