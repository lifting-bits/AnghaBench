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
struct svc_rqst {int dummy; } ;
struct nlm_args {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  NLMPROC_TEST_RES ; 
 int /*<<< orphan*/  dprintk (char*) ; 
 int /*<<< orphan*/  nlmsvc_callback (struct svc_rqst*,int /*<<< orphan*/ ,struct nlm_args*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nlmsvc_proc_test ; 

__attribute__((used)) static __be32 nlmsvc_proc_test_msg(struct svc_rqst *rqstp, struct nlm_args *argp,
					     void	     *resp)
{
	dprintk("lockd: TEST_MSG      called\n");
	return nlmsvc_callback(rqstp, NLMPROC_TEST_RES, argp, nlmsvc_proc_test);
}