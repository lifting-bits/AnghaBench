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
typedef  int /*<<< orphan*/  svn_branch__history_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/ * svn_branch__history_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

svn_branch__history_t *
svn_branch__history_create_empty(apr_pool_t *result_pool)
{
  svn_branch__history_t *history
    = svn_branch__history_create(NULL, result_pool);

  return history;
}