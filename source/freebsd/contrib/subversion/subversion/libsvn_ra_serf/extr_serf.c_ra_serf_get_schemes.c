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

__attribute__((used)) static const char * const *
ra_serf_get_schemes(apr_pool_t *pool)
{
  static const char *serf_ssl[] = { "http", "https", NULL };
#if 0
  /* ### Temporary: to shut up a warning. */
  static const char *serf_no_ssl[] = { "http", NULL };
#endif

  /* TODO: Runtime detection. */
  return serf_ssl;
}