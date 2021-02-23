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
typedef  int /*<<< orphan*/  bfd ;

/* Variables and functions */
 char* bfd_get_filename (int /*<<< orphan*/ *) ; 
 scalar_t__ filename_per_symbol ; 
 int /*<<< orphan*/  printf (char*,char*,...) ; 

__attribute__((used)) static void
print_symbol_filename_posix (bfd *archive_bfd, bfd *abfd)
{
  if (filename_per_symbol)
    {
      if (archive_bfd)
	printf ("%s[%s]: ", bfd_get_filename (archive_bfd),
		bfd_get_filename (abfd));
      else
	printf ("%s: ", bfd_get_filename (abfd));
    }
}