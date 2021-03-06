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
struct rad_handle {int dummy; } ;
struct in6_addr {int /*<<< orphan*/  s6_addr; } ;

/* Variables and functions */
 int rad_put_attr (struct rad_handle*,int,int /*<<< orphan*/ *,int) ; 

int
rad_put_addr6(struct rad_handle *h, int type, struct in6_addr addr)
{

	return rad_put_attr(h, type, &addr.s6_addr, sizeof addr.s6_addr);
}