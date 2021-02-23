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
typedef  int /*<<< orphan*/  svnlook_ctxt_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
struct svnlook_opt_state {int dummy; } ;
typedef  int /*<<< orphan*/  apr_pool_t ;
typedef  int /*<<< orphan*/  apr_getopt_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  check_number_of_args (struct svnlook_opt_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_dirs_changed (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  get_ctxt_baton (int /*<<< orphan*/ **,struct svnlook_opt_state*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static svn_error_t *
subcommand_dirschanged(apr_getopt_t *os, void *baton, apr_pool_t *pool)
{
  struct svnlook_opt_state *opt_state = baton;
  svnlook_ctxt_t *c;

  SVN_ERR(check_number_of_args(opt_state, 0));

  SVN_ERR(get_ctxt_baton(&c, opt_state, pool));
  SVN_ERR(do_dirs_changed(c, pool));
  return SVN_NO_ERROR;
}