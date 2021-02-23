#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  svn_error_t ;
struct TYPE_2__ {scalar_t__ digest; } ;
typedef  TYPE_1__ stream_baton_t ;
typedef  int /*<<< orphan*/  apr_uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  close_handler (void*) ; 
 int /*<<< orphan*/  ntohl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static svn_error_t *
close_handler_fnv1a_32x4(void *baton)
{
  stream_baton_t *b = baton;
  SVN_ERR(close_handler(baton));

  *(apr_uint32_t *)b->digest = ntohl(*(apr_uint32_t *)b->digest);
  return SVN_NO_ERROR;
}