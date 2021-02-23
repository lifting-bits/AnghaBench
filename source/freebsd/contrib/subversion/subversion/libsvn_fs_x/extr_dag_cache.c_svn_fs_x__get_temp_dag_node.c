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
typedef  int /*<<< orphan*/  svn_string_t ;
typedef  int /*<<< orphan*/  svn_fs_root_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  dag_node_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/ * dag_node_cache_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  normalize_path (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  walk_dag_path (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

svn_error_t *
svn_fs_x__get_temp_dag_node(dag_node_t **node_p,
                            svn_fs_root_t *root,
                            const char *path,
                            apr_pool_t *scratch_pool)
{
  svn_string_t normalized;

  /* First we look for the DAG in our cache. */
  *node_p = dag_node_cache_get(root, normalize_path(&normalized, path));

  /* If it is not there, walk the DAG and fill the cache. */
  if (! *node_p)
    SVN_ERR(walk_dag_path(node_p, root, &normalized, scratch_pool));

  return SVN_NO_ERROR;
}