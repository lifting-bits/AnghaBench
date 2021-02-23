#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct cleanup {int dummy; } ;
typedef  int /*<<< orphan*/  ps_err_e ;
typedef  int /*<<< orphan*/  lwpid_t ;
typedef  TYPE_1__* gdb_ps_prochandle_t ;
typedef  int /*<<< orphan*/  gdb_prfpregset_t ;
typedef  int /*<<< orphan*/  gdb_fpregset_t ;
struct TYPE_3__ {int /*<<< orphan*/  pid; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUILD_LWP (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PS_OK ; 
 int /*<<< orphan*/  do_cleanups (struct cleanup*) ; 
 int /*<<< orphan*/  inferior_ptid ; 
 struct cleanup* save_inferior_ptid () ; 
 int /*<<< orphan*/  supply_fpregset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  target_store_registers (int) ; 

ps_err_e
ps_lsetfpregs (gdb_ps_prochandle_t ph, lwpid_t lwpid,
	       const gdb_prfpregset_t *fpregset)
{
  struct cleanup *old_chain = save_inferior_ptid ();

  inferior_ptid = BUILD_LWP (lwpid, ph->pid);

  /* FIXME: We should really make supply_fpregset const-correct.  */
  supply_fpregset ((gdb_fpregset_t *) fpregset);
  target_store_registers (-1);

  do_cleanups (old_chain);
  return PS_OK;
}