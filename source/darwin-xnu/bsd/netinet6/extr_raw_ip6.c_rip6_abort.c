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
struct socket {int dummy; } ;

/* Variables and functions */
 int rip6_detach (struct socket*) ; 
 int /*<<< orphan*/  soisdisconnected (struct socket*) ; 

__attribute__((used)) static int
rip6_abort(struct socket *so)
{
	soisdisconnected(so);
	return rip6_detach(so);
}