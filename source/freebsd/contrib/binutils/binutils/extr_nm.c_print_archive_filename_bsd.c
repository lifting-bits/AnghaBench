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
 scalar_t__ filename_per_file ; 
 int /*<<< orphan*/  printf (char*,char*) ; 

__attribute__((used)) static void
print_archive_filename_bsd (char *filename)
{
  if (filename_per_file)
    printf ("\n%s:\n", filename);
}