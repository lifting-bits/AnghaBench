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

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  svn_cmdline_fputs (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_cmdline_printf (int /*<<< orphan*/ *,char*,char const*,char const*) ; 

__attribute__((used)) static svn_error_t *
print_info_item_string(const char *text, const char *target_path,
                       apr_pool_t *pool)
{
  if (text)
    {
      if (target_path)
        SVN_ERR(svn_cmdline_printf(pool, "%-10s %s", text, target_path));
      else
        SVN_ERR(svn_cmdline_fputs(text, stdout, pool));
    }
  else if (target_path)
    SVN_ERR(svn_cmdline_printf(pool, "%-10s %s", "", target_path));

  return SVN_NO_ERROR;
}