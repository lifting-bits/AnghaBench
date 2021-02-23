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
typedef  int /*<<< orphan*/  svn_stringbuf_t ;
typedef  int /*<<< orphan*/  svn_revnum_t ;
typedef  int /*<<< orphan*/  svn_fs_x__txn_id_t ;
struct TYPE_4__ {int /*<<< orphan*/ * fs; } ;
typedef  TYPE_1__ svn_fs_txn_t ;
typedef  int /*<<< orphan*/  svn_fs_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  dag_node_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SVN_ERR_MALFUNCTION () ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  merge (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_fs_x__change_set_by_rev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_fs_x__change_set_by_txn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_fs_x__dag_related_node (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_fs_x__dag_root (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_fs_x__get_base_rev (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_fs_x__txn_get_id (TYPE_1__*) ; 

__attribute__((used)) static svn_error_t *
merge_changes(dag_node_t *ancestor_node,
              dag_node_t *source_node,
              svn_fs_txn_t *txn,
              svn_stringbuf_t *conflict,
              apr_pool_t *scratch_pool)
{
  dag_node_t *txn_root_node;
  svn_fs_t *fs = txn->fs;
  svn_fs_x__txn_id_t txn_id = svn_fs_x__txn_get_id(txn);

  SVN_ERR(svn_fs_x__dag_root(&txn_root_node, fs,
                             svn_fs_x__change_set_by_txn(txn_id),
                             scratch_pool, scratch_pool));

  if (ancestor_node == NULL)
    {
      svn_revnum_t base_rev;
      SVN_ERR(svn_fs_x__get_base_rev(&base_rev, fs, txn_id, scratch_pool));
      SVN_ERR(svn_fs_x__dag_root(&ancestor_node, fs,
                                 svn_fs_x__change_set_by_rev(base_rev),
                                 scratch_pool, scratch_pool));
    }

  if (!svn_fs_x__dag_related_node(ancestor_node, txn_root_node))
    {
      /* If no changes have been made in TXN since its current base,
         then it can't conflict with any changes since that base.
         The caller isn't supposed to call us in that case. */
      SVN_ERR_MALFUNCTION();
    }
  else
    SVN_ERR(merge(conflict, "/", txn_root_node,
                  source_node, ancestor_node, txn_id, NULL, scratch_pool));

  return SVN_NO_ERROR;
}