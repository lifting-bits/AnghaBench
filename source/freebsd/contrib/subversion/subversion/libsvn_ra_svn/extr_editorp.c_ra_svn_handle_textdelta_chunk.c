#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  len; int /*<<< orphan*/  data; } ;
typedef  TYPE_1__ svn_string_t ;
typedef  int /*<<< orphan*/  svn_ra_svn_conn_t ;
typedef  int /*<<< orphan*/  svn_ra_svn__list_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
struct TYPE_8__ {int /*<<< orphan*/  dstream; } ;
typedef  TYPE_2__ ra_svn_token_entry_t ;
typedef  int /*<<< orphan*/  ra_svn_driver_state_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_CMD_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SVN_ERR_RA_SVN_MALFORMED_DATA ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  lookup_token (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ ,TYPE_2__**) ; 
 int /*<<< orphan*/ * svn_error_create (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_ra_svn__parse_tuple (int /*<<< orphan*/  const*,char*,TYPE_1__**,TYPE_1__**) ; 
 int /*<<< orphan*/  svn_stream_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static svn_error_t *
ra_svn_handle_textdelta_chunk(svn_ra_svn_conn_t *conn,
                              apr_pool_t *pool,
                              const svn_ra_svn__list_t *params,
                              ra_svn_driver_state_t *ds)
{
  svn_string_t *token;
  ra_svn_token_entry_t *entry;
  svn_string_t *str;

  /* Parse arguments and look up the token. */
  SVN_ERR(svn_ra_svn__parse_tuple(params, "ss", &token, &str));
  SVN_ERR(lookup_token(ds, token, TRUE, &entry));
  if (!entry->dstream)
    return svn_error_create(SVN_ERR_RA_SVN_MALFORMED_DATA, NULL,
                            _("Apply-textdelta not active"));
  SVN_CMD_ERR(svn_stream_write(entry->dstream, str->data, &str->len));
  return SVN_NO_ERROR;
}