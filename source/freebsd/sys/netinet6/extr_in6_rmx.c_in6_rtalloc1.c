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
typedef  int /*<<< orphan*/  u_long ;
typedef  int /*<<< orphan*/  u_int ;
struct sockaddr {int dummy; } ;
struct rtentry {int dummy; } ;

/* Variables and functions */
 struct rtentry* rtalloc1_fib (struct sockaddr*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

struct rtentry *
in6_rtalloc1(struct sockaddr *dst, int report, u_long ignflags, u_int fibnum)
{

	return (rtalloc1_fib(dst, report, ignflags, fibnum));
}