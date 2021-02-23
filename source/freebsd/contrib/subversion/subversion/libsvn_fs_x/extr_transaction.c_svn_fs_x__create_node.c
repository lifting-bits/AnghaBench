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
typedef  int /*<<< orphan*/  svn_fs_x__txn_id_t ;
struct TYPE_5__ {int /*<<< orphan*/  number; int /*<<< orphan*/  change_set; } ;
struct TYPE_6__ {TYPE_1__ noderev_id; int /*<<< orphan*/  copy_id; int /*<<< orphan*/  node_id; } ;
typedef  TYPE_2__ svn_fs_x__noderev_t ;
typedef  int /*<<< orphan*/  svn_fs_x__id_t ;
typedef  int /*<<< orphan*/  svn_fs_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  allocate_item_index (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  get_new_txn_node_id (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_fs_x__change_set_by_txn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_fs_x__put_node_revision (int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ *) ; 

svn_error_t *
svn_fs_x__create_node(svn_fs_t *fs,
                      svn_fs_x__noderev_t *noderev,
                      const svn_fs_x__id_t *copy_id,
                      svn_fs_x__txn_id_t txn_id,
                      apr_pool_t *scratch_pool)
{
  /* Get a new node-id for this node. */
  SVN_ERR(get_new_txn_node_id(&noderev->node_id, fs, txn_id, scratch_pool));

  /* Assign copy-id. */
  noderev->copy_id = *copy_id;

  /* Noderev-id = Change set and item number within this change set. */
  noderev->noderev_id.change_set = svn_fs_x__change_set_by_txn(txn_id);
  SVN_ERR(allocate_item_index(&noderev->noderev_id.number, fs, txn_id,
                              scratch_pool));

  SVN_ERR(svn_fs_x__put_node_revision(fs, noderev, scratch_pool));

  return SVN_NO_ERROR;
}