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
struct netconfig {int dummy; } ;
struct __rpc_sockinfo {int /*<<< orphan*/  si_proto; int /*<<< orphan*/  si_socktype; int /*<<< orphan*/  si_af; } ;

/* Variables and functions */
 int /*<<< orphan*/  __rpc_nconf2sockinfo (struct netconfig const*,struct __rpc_sockinfo*) ; 
 int _socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
__rpc_nconf2fd(const struct netconfig *nconf)
{
	struct __rpc_sockinfo si;

	if (!__rpc_nconf2sockinfo(nconf, &si))
		return 0;

	return _socket(si.si_af, si.si_socktype, si.si_proto);
}