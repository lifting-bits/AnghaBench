#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  target; int /*<<< orphan*/ * props; int /*<<< orphan*/  kind; int /*<<< orphan*/ * pool; } ;
typedef  TYPE_1__ svn_element__payload_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;
typedef  int /*<<< orphan*/  apr_hash_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR_ASSERT_NO_RETURN (char const*) ; 
 TYPE_1__* apr_pcalloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  apr_pstrdup (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_element__payload_invariants (TYPE_1__*) ; 
 int /*<<< orphan*/  svn_node_symlink ; 
 int /*<<< orphan*/ * svn_prop_hash_dup (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

svn_element__payload_t *
svn_element__payload_create_symlink(apr_hash_t *props,
                                    const char *target,
                                    apr_pool_t *result_pool)
{
  svn_element__payload_t *new_payload
    = apr_pcalloc(result_pool, sizeof(*new_payload));

  SVN_ERR_ASSERT_NO_RETURN(target);

  new_payload->pool = result_pool;
  new_payload->kind = svn_node_symlink;
  new_payload->props = props ? svn_prop_hash_dup(props, result_pool) : NULL;
  new_payload->target = apr_pstrdup(result_pool, target);
  assert(svn_element__payload_invariants(new_payload));
  return new_payload;
}