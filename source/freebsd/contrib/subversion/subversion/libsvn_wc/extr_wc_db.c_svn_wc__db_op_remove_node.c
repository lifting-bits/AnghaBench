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
typedef  int /*<<< orphan*/  svn_wc__db_wcroot_t ;
typedef  int /*<<< orphan*/  svn_wc__db_t ;
typedef  int /*<<< orphan*/  svn_skel_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  svn_cancel_func_t ;
typedef  int /*<<< orphan*/  svn_boolean_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SVN_ERR_ASSERT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  SVN_WC__DB_WITH_TXN (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  VERIFY_USABLE_WCROOT (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  flush_entries (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  remove_node_txn (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_depth_infinity ; 
 int /*<<< orphan*/  svn_dirent_is_absolute (char const*) ; 
 int /*<<< orphan*/  svn_wc__db_wcroot_parse_local_abspath (int /*<<< orphan*/ **,char const**,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

svn_error_t *
svn_wc__db_op_remove_node(svn_boolean_t *left_changes,
                          svn_wc__db_t *db,
                          const char *local_abspath,
                          svn_boolean_t destroy_wc,
                          svn_boolean_t destroy_changes,
                          const svn_skel_t *conflict,
                          const svn_skel_t *work_items,
                          svn_cancel_func_t cancel_func,
                          void *cancel_baton,
                          apr_pool_t *scratch_pool)
{
  svn_wc__db_wcroot_t *wcroot;
  const char *local_relpath;

  SVN_ERR_ASSERT(svn_dirent_is_absolute(local_abspath));

  SVN_ERR(svn_wc__db_wcroot_parse_local_abspath(&wcroot, &local_relpath, db,
                              local_abspath, scratch_pool, scratch_pool));
  VERIFY_USABLE_WCROOT(wcroot);

  SVN_WC__DB_WITH_TXN(remove_node_txn(left_changes,
                                      wcroot, local_relpath, db,
                                      destroy_wc, destroy_changes,
                                      conflict, work_items,
                                      cancel_func, cancel_baton, scratch_pool),
                      wcroot);

  /* Flush everything below this node in all ways */
  SVN_ERR(flush_entries(wcroot, local_abspath, svn_depth_infinity,
                        scratch_pool));

  return SVN_NO_ERROR;
}