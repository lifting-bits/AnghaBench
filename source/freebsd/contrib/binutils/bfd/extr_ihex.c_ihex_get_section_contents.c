#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int file_ptr ;
typedef  scalar_t__ bfd_size_type ;
typedef  int /*<<< orphan*/  bfd_byte ;
typedef  int /*<<< orphan*/  bfd_boolean ;
typedef  int /*<<< orphan*/  bfd ;
struct TYPE_4__ {int /*<<< orphan*/ * used_by_bfd; int /*<<< orphan*/  size; } ;
typedef  TYPE_1__ asection ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/ * bfd_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ihex_read_section (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (void*,int /*<<< orphan*/ *,size_t) ; 

__attribute__((used)) static bfd_boolean
ihex_get_section_contents (bfd *abfd,
			   asection *section,
			   void * location,
			   file_ptr offset,
			   bfd_size_type count)
{
  if (section->used_by_bfd == NULL)
    {
      section->used_by_bfd = bfd_alloc (abfd, section->size);
      if (section->used_by_bfd == NULL)
	return FALSE;
      if (! ihex_read_section (abfd, section, section->used_by_bfd))
	return FALSE;
    }

  memcpy (location, (bfd_byte *) section->used_by_bfd + offset,
	  (size_t) count);

  return TRUE;
}