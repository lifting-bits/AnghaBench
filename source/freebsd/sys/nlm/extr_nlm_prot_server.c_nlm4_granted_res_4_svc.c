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
struct svc_req {int dummy; } ;
typedef  int /*<<< orphan*/  nlm4_res ;
typedef  int /*<<< orphan*/  bool_t ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  nlm_do_granted_res (int /*<<< orphan*/ *,struct svc_req*) ; 

bool_t
nlm4_granted_res_4_svc(nlm4_res *argp, void *result, struct svc_req *rqstp)
{

	nlm_do_granted_res(argp, rqstp);
	return (FALSE);
}