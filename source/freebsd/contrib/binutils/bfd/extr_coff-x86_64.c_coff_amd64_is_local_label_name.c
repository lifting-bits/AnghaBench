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
typedef  int /*<<< orphan*/  bfd_boolean ;
typedef  int /*<<< orphan*/  bfd ;

/* Variables and functions */
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  _bfd_coff_is_local_label_name (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static bfd_boolean
coff_amd64_is_local_label_name (bfd *abfd, const char *name)
{
  if (name[0] == 'L')
    return TRUE;

  return _bfd_coff_is_local_label_name (abfd, name);
}