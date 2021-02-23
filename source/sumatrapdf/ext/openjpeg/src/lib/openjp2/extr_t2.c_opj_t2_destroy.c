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
typedef  int /*<<< orphan*/  opj_t2_t ;

/* Variables and functions */
 int /*<<< orphan*/  opj_free (int /*<<< orphan*/ *) ; 

void opj_t2_destroy(opj_t2_t *t2)
{
    if (t2) {
        opj_free(t2);
    }
}