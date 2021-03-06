#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {struct TYPE_5__* signature_job; struct TYPE_5__* checksum_job; struct TYPE_5__* settings_job; struct TYPE_5__* roothash_job; struct TYPE_5__* raw_job; } ;
typedef  TYPE_1__ RawPull ;

/* Variables and functions */
 int /*<<< orphan*/  PULL_JOB_IS_COMPLETE (TYPE_1__*) ; 
 int /*<<< orphan*/  assert (TYPE_1__*) ; 

__attribute__((used)) static bool raw_pull_is_done(RawPull *i) {
        assert(i);
        assert(i->raw_job);

        if (!PULL_JOB_IS_COMPLETE(i->raw_job))
                return false;
        if (i->roothash_job && !PULL_JOB_IS_COMPLETE(i->roothash_job))
                return false;
        if (i->settings_job && !PULL_JOB_IS_COMPLETE(i->settings_job))
                return false;
        if (i->checksum_job && !PULL_JOB_IS_COMPLETE(i->checksum_job))
                return false;
        if (i->signature_job && !PULL_JOB_IS_COMPLETE(i->signature_job))
                return false;

        return true;
}