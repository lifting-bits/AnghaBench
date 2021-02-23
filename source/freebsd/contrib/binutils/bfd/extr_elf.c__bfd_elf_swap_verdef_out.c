#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  bfd ;
struct TYPE_6__ {int /*<<< orphan*/  vd_next; int /*<<< orphan*/  vd_aux; int /*<<< orphan*/  vd_hash; int /*<<< orphan*/  vd_cnt; int /*<<< orphan*/  vd_ndx; int /*<<< orphan*/  vd_flags; int /*<<< orphan*/  vd_version; } ;
struct TYPE_5__ {int /*<<< orphan*/  vd_next; int /*<<< orphan*/  vd_aux; int /*<<< orphan*/  vd_hash; int /*<<< orphan*/  vd_cnt; int /*<<< orphan*/  vd_ndx; int /*<<< orphan*/  vd_flags; int /*<<< orphan*/  vd_version; } ;
typedef  TYPE_1__ Elf_Internal_Verdef ;
typedef  TYPE_2__ Elf_External_Verdef ;

/* Variables and functions */
 int /*<<< orphan*/  H_PUT_16 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  H_PUT_32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
_bfd_elf_swap_verdef_out (bfd *abfd,
			  const Elf_Internal_Verdef *src,
			  Elf_External_Verdef *dst)
{
  H_PUT_16 (abfd, src->vd_version, dst->vd_version);
  H_PUT_16 (abfd, src->vd_flags, dst->vd_flags);
  H_PUT_16 (abfd, src->vd_ndx, dst->vd_ndx);
  H_PUT_16 (abfd, src->vd_cnt, dst->vd_cnt);
  H_PUT_32 (abfd, src->vd_hash, dst->vd_hash);
  H_PUT_32 (abfd, src->vd_aux, dst->vd_aux);
  H_PUT_32 (abfd, src->vd_next, dst->vd_next);
}