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
 int /*<<< orphan*/  gdbsim_desc ; 
 int /*<<< orphan*/  quit () ; 
 int /*<<< orphan*/  sim_stop (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
gdbsim_stop (void)
{
  if (!sim_stop (gdbsim_desc))
    {
      quit ();
    }
}