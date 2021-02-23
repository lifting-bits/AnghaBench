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
typedef  int /*<<< orphan*/  svn_io_dirent2_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  svn_boolean_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/ * svn_error_trace (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_io_stat_dirent2 (int /*<<< orphan*/  const**,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

svn_error_t *
svn_io_stat_dirent(const svn_io_dirent2_t **dirent_p,
                   const char *path,
                   svn_boolean_t ignore_enoent,
                   apr_pool_t *result_pool,
                   apr_pool_t *scratch_pool)
{
  return svn_error_trace(
            svn_io_stat_dirent2(dirent_p,
                                path,
                                FALSE,
                                ignore_enoent,
                                result_pool,
                                scratch_pool));
}