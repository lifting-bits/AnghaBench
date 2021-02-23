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
struct xfrm_state {int dummy; } ;

/* Variables and functions */
 int __xfrm6_sort (void**,void**,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  __xfrm6_state_sort_cmp ; 

__attribute__((used)) static int
__xfrm6_state_sort(struct xfrm_state **dst, struct xfrm_state **src, int n)
{
	return __xfrm6_sort((void **)dst, (void **)src, n,
			    __xfrm6_state_sort_cmp, 6);
}