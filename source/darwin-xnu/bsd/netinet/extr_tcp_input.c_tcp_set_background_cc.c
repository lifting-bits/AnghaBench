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
 int /*<<< orphan*/  TCP_CC_ALGO_BACKGROUND_INDEX ; 
 int /*<<< orphan*/  tcp_set_new_cc (struct socket*,int /*<<< orphan*/ ) ; 

void
tcp_set_background_cc(struct socket *so)
{
	tcp_set_new_cc(so, TCP_CC_ALGO_BACKGROUND_INDEX);
}