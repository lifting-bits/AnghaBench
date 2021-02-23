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
struct inpcb {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  KASSERT (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  soisdisconnected (struct socket*) ; 
 struct inpcb* sotoinpcb (struct socket*) ; 

__attribute__((used)) static void
rip6_close(struct socket *so)
{
	struct inpcb *inp;

	inp = sotoinpcb(so);
	KASSERT(inp != NULL, ("rip6_close: inp == NULL"));

	soisdisconnected(so);
}