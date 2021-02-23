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
 int annotation_level ; 
 int /*<<< orphan*/  printf_unfiltered (char*) ; 
 int /*<<< orphan*/  target_terminal_ours () ; 

void
annotate_frames_invalid (void)
{
  if (annotation_level > 1)
    {
      target_terminal_ours ();
      printf_unfiltered ("\n\032\032frames-invalid\n");
    }
}