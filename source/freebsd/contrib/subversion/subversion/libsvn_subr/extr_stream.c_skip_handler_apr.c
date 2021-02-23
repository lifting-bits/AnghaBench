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
struct baton_apr {int /*<<< orphan*/  pool; int /*<<< orphan*/  file; } ;
typedef  int /*<<< orphan*/  apr_size_t ;
typedef  int /*<<< orphan*/  apr_off_t ;

/* Variables and functions */
 int /*<<< orphan*/  APR_CUR ; 
 int /*<<< orphan*/ * svn_error_trace (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_io_file_seek (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static svn_error_t *
skip_handler_apr(void *baton, apr_size_t len)
{
  struct baton_apr *btn = baton;
  apr_off_t offset = len;

  return svn_error_trace(
            svn_io_file_seek(btn->file, APR_CUR, &offset, btn->pool));
}