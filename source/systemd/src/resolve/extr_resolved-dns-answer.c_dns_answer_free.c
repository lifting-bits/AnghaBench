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
typedef  int /*<<< orphan*/  DnsAnswer ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dns_answer_flush (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * mfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static DnsAnswer *dns_answer_free(DnsAnswer *a) {
        assert(a);

        dns_answer_flush(a);
        return mfree(a);
}