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
struct bfa_iocpf {int /*<<< orphan*/  ioc; scalar_t__ poll_time; } ;

/* Variables and functions */
 int /*<<< orphan*/  bfa_ioc_reset (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
bfa_iocpf_sm_hwinit_entry(struct bfa_iocpf *iocpf)
{
	iocpf->poll_time = 0;
	bfa_ioc_reset(iocpf->ioc, false);
}