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
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;
typedef  int /*<<< orphan*/  apr_getopt_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  list_dblogs (int /*<<< orphan*/ *,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  parse_args (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static svn_error_t *
subcommand_list_unused_dblogs(apr_getopt_t *os, void *baton, apr_pool_t *pool)
{
  /* Expect no more arguments. */
  SVN_ERR(parse_args(NULL, os, 0, 0, pool));

  SVN_ERR(list_dblogs(os, baton, TRUE, pool));
  return SVN_NO_ERROR;
}