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
 scalar_t__ AMD64_NUM_GREGS ; 
 scalar_t__ ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GDB_OSABI_NETBSD_AOUT ; 
 int /*<<< orphan*/  GDB_OSABI_OPENBSD_ELF ; 
 int /*<<< orphan*/  amd64obsd_init_abi ; 
 int /*<<< orphan*/  amd64obsd_r_reg_offset ; 
 int /*<<< orphan*/  bfd_arch_i386 ; 
 int /*<<< orphan*/  bfd_mach_x86_64 ; 
 int /*<<< orphan*/  gdb_assert (int) ; 
 int /*<<< orphan*/  gdbarch_register_osabi (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
_initialize_amd64obsd_tdep (void)
{
  /* The OpenBSD/amd64 native dependent code makes this assumption.  */
  gdb_assert (ARRAY_SIZE (amd64obsd_r_reg_offset) == AMD64_NUM_GREGS);

  gdbarch_register_osabi (bfd_arch_i386, bfd_mach_x86_64,
			  GDB_OSABI_OPENBSD_ELF, amd64obsd_init_abi);

  /* OpenBSD uses traditional (a.out) NetBSD-style core dumps.  */
  gdbarch_register_osabi (bfd_arch_i386, bfd_mach_x86_64,
			  GDB_OSABI_NETBSD_AOUT, amd64obsd_init_abi);
}