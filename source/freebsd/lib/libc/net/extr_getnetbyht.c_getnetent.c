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
struct netent {int dummy; } ;
struct netdata {int /*<<< orphan*/  data; int /*<<< orphan*/  net; } ;

/* Variables and functions */
 struct netdata* __netdata_init () ; 
 scalar_t__ getnetent_r (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,struct netent**,int*) ; 

struct netent *
getnetent(void)
{
	struct netdata *nd;
	struct netent *rval;
	int ret_h_errno;

	if ((nd = __netdata_init()) == NULL)
		return (NULL);
	if (getnetent_r(&nd->net, nd->data, sizeof(nd->data), &rval,
	    &ret_h_errno) != 0)
		return (NULL);
	return (rval);
}