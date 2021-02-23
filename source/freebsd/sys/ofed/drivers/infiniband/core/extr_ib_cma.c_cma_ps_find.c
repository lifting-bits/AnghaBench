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
struct vnet {int dummy; } ;
struct rdma_bind_list {int dummy; } ;
struct idr {int dummy; } ;
typedef  enum rdma_port_space { ____Placeholder_rdma_port_space } rdma_port_space ;

/* Variables and functions */
 struct idr* cma_pernet_idr (struct vnet*,int) ; 
 struct rdma_bind_list* idr_find (struct idr*,int) ; 

__attribute__((used)) static struct rdma_bind_list *cma_ps_find(struct vnet *net,
					  enum rdma_port_space ps, int snum)
{
	struct idr *idr = cma_pernet_idr(net, ps);

	return idr_find(idr, snum);
}