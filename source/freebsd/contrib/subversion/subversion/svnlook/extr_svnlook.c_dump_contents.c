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
typedef  int /*<<< orphan*/  svn_stream_t ;
typedef  int /*<<< orphan*/  svn_fs_root_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  svn_fs_file_contents (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_stream_close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_stream_copy3 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static svn_error_t *
dump_contents(svn_stream_t *stream,
              svn_fs_root_t *root,
              const char *path /* UTF-8! */,
              apr_pool_t *pool)
{
  if (root == NULL)
    SVN_ERR(svn_stream_close(stream));  /* leave an empty file */
  else
    {
      svn_stream_t *contents;

      /* Grab the contents and copy them into the given stream. */
      SVN_ERR(svn_fs_file_contents(&contents, root, path, pool));
      SVN_ERR(svn_stream_copy3(contents, stream, NULL, NULL, pool));
    }

  return SVN_NO_ERROR;
}