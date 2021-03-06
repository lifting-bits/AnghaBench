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
typedef  int u64 ;

/* Variables and functions */
 int TB_ROUTE_SHIFT ; 
 int tb_route_length (int) ; 

__attribute__((used)) static inline u64 get_parent_route(u64 route)
{
	int depth = tb_route_length(route);
	return depth ? route & ~(0xffULL << (depth - 1) * TB_ROUTE_SHIFT) : 0;
}