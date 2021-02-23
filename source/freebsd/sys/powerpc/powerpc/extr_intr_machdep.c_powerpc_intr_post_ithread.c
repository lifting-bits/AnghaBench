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
struct powerpc_intr {int /*<<< orphan*/  priv; int /*<<< orphan*/  intline; int /*<<< orphan*/  pic; } ;

/* Variables and functions */
 int /*<<< orphan*/  PIC_UNMASK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
powerpc_intr_post_ithread(void *arg)
{
	struct powerpc_intr *i = arg;

	PIC_UNMASK(i->pic, i->intline, i->priv);
}