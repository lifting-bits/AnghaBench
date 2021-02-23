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
typedef  int /*<<< orphan*/  asection ;

/* Variables and functions */
 int /*<<< orphan*/ * bfd_make_section_with_flags (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 

asection *
bfd_make_section (bfd *abfd, const char *name)
{
  return bfd_make_section_with_flags (abfd, name, 0);
}