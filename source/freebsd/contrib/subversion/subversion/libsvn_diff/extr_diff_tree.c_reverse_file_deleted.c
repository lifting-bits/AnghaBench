#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  svn_error_t ;
struct TYPE_4__ {struct reverse_tree_baton_t* baton; } ;
typedef  TYPE_1__ svn_diff_tree_processor_t ;
typedef  int /*<<< orphan*/  svn_diff_source_t ;
struct reverse_tree_baton_t {TYPE_2__* processor; scalar_t__ prefix_relpath; } ;
typedef  int /*<<< orphan*/  apr_pool_t ;
typedef  int /*<<< orphan*/  apr_hash_t ;
struct TYPE_5__ {int /*<<< orphan*/  (* file_added ) (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,void*,TYPE_2__*,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  stub1 (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,void*,TYPE_2__*,int /*<<< orphan*/ *) ; 
 char* svn_relpath_join (scalar_t__,char const*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static svn_error_t *
reverse_file_deleted(const char *relpath,
                     const svn_diff_source_t *left_source,
                     const char *left_file,
                     /*const*/ apr_hash_t *left_props,
                     void *file_baton,
                     const svn_diff_tree_processor_t *processor,
                     apr_pool_t *scratch_pool)
{
  struct reverse_tree_baton_t *rb = processor->baton;

  if (rb->prefix_relpath)
    relpath = svn_relpath_join(rb->prefix_relpath, relpath, scratch_pool);

  SVN_ERR(rb->processor->file_added(relpath,
                                    NULL /* copyfrom src */,
                                    left_source,
                                    NULL /* copyfrom file */,
                                    left_file,
                                    NULL /* copyfrom props */,
                                    left_props,
                                    file_baton,
                                    rb->processor,
                                    scratch_pool));
  return SVN_NO_ERROR;
}