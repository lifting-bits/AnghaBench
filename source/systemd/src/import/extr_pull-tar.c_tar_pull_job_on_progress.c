#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {struct TYPE_6__* userdata; } ;
typedef  TYPE_1__ TarPull ;
typedef  TYPE_1__ PullJob ;

/* Variables and functions */
 int /*<<< orphan*/  TAR_DOWNLOADING ; 
 int /*<<< orphan*/  assert (TYPE_1__*) ; 
 int /*<<< orphan*/  tar_pull_report_progress (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void tar_pull_job_on_progress(PullJob *j) {
        TarPull *i;

        assert(j);
        assert(j->userdata);

        i = j->userdata;

        tar_pull_report_progress(i, TAR_DOWNLOADING);
}