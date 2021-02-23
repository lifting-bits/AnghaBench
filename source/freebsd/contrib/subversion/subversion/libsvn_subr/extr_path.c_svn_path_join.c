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
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 char* svn_path_join_internal (char const*,char const*,int /*<<< orphan*/ *) ; 

char *svn_path_join(const char *base,
                    const char *component,
                    apr_pool_t *pool)
{
  return svn_path_join_internal(base, component, pool);
}