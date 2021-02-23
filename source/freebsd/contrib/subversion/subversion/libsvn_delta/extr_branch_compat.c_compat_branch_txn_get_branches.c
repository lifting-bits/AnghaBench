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
struct TYPE_5__ {TYPE_1__* priv; } ;
typedef  TYPE_2__ svn_branch__txn_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;
typedef  int /*<<< orphan*/  apr_array_header_t ;
struct TYPE_4__ {int /*<<< orphan*/  txn; } ;

/* Variables and functions */
 int /*<<< orphan*/ * svn_branch__txn_get_branches (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static apr_array_header_t *
compat_branch_txn_get_branches(const svn_branch__txn_t *txn,
                               apr_pool_t *result_pool)
{
  /* Just forwarding: nothing more is needed. */
  apr_array_header_t *branches
    = svn_branch__txn_get_branches(txn->priv->txn,
                                   result_pool);

  return branches;
}