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
struct o2net_sock_container {int dummy; } ;
struct o2net_send_tracking {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void o2net_set_nst_sock_container(struct o2net_send_tracking *nst,
						struct o2net_sock_container *sc)
{
}