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

/* Variables and functions */
 int /*<<< orphan*/  generic_mourn_inferior () ; 
 int /*<<< orphan*/  targ_ops ; 
 int /*<<< orphan*/  unpush_target (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
monitor_mourn_inferior (void)
{
  unpush_target (targ_ops);
  generic_mourn_inferior ();	/* Do all the proper things now */
}