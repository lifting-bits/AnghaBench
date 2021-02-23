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
struct cfi_insn_data {int insn; } ;

/* Variables and functions */
 struct cfi_insn_data* alloc_cfi_insn_data () ; 

__attribute__((used)) static void
cfi_add_CFA_insn(int insn)
{
  struct cfi_insn_data *insn_ptr = alloc_cfi_insn_data ();

  insn_ptr->insn = insn;
}