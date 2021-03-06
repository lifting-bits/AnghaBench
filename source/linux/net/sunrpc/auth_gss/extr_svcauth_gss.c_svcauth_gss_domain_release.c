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
struct auth_domain {int /*<<< orphan*/  rcu_head; } ;

/* Variables and functions */
 int /*<<< orphan*/  call_rcu (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svcauth_gss_domain_release_rcu ; 

__attribute__((used)) static void
svcauth_gss_domain_release(struct auth_domain *dom)
{
	call_rcu(&dom->rcu_head, svcauth_gss_domain_release_rcu);
}