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
struct bfa_lps_s {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_LPS_SM_RESUME ; 
 int /*<<< orphan*/  bfa_sm_send_event (struct bfa_lps_s*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bfa_lps_reqq_resume(void *lps_arg)
{
	struct bfa_lps_s	*lps = lps_arg;

	bfa_sm_send_event(lps, BFA_LPS_SM_RESUME);
}