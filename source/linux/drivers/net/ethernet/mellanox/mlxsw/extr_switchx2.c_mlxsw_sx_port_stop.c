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
struct net_device {int dummy; } ;
struct mlxsw_sx_port {int dummy; } ;

/* Variables and functions */
 int mlxsw_sx_port_admin_status_set (struct mlxsw_sx_port*,int) ; 
 struct mlxsw_sx_port* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 

__attribute__((used)) static int mlxsw_sx_port_stop(struct net_device *dev)
{
	struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);

	netif_stop_queue(dev);
	return mlxsw_sx_port_admin_status_set(mlxsw_sx_port, false);
}