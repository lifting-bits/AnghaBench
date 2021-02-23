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
struct nn_binproc {int /*<<< orphan*/  fsm; } ;

/* Variables and functions */
 int /*<<< orphan*/  nn_fsm_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void nn_binproc_stop (void *self)
{
    struct nn_binproc *binproc = self;

    nn_fsm_stop (&binproc->fsm);
}