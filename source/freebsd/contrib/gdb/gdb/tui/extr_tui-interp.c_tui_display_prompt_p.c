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
 scalar_t__ interp_quiet_p (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
tui_display_prompt_p (void *data)
{
  if (interp_quiet_p (NULL))
    return 0;
  else
    return 1;
}