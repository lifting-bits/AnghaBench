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
struct test {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int priv_netinet_ipsec_policy_entrust_setup_af (int,int,struct test*,int /*<<< orphan*/ ) ; 

int
priv_netinet_ipsec_policy4_entrust_setup(int asroot, int injail,
    struct test *test)
{

	return (priv_netinet_ipsec_policy_entrust_setup_af(asroot, injail, test,
	    AF_INET));
}