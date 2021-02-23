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
typedef  int /*<<< orphan*/  asymbol ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  bfd_map_over_sections (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  bfd_scan_vma (char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  find_address_in_section ; 
 int /*<<< orphan*/  found ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 int line ; 
 int /*<<< orphan*/  pc ; 

__attribute__((used)) static void
translate_addresses (bfd *abfd, char *addr_hex, FILE *f, asymbol **syms)
{
  pc = bfd_scan_vma (addr_hex, NULL, 16);
  found = FALSE;
  bfd_map_over_sections (abfd, find_address_in_section, syms);

  if (! found)
    fprintf (f, "??");
  else
    fprintf (f, "%u", line);
}