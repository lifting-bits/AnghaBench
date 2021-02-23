#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {scalar_t__ handle; } ;
typedef  TYPE_1__ xlate_handle_node_t ;
struct TYPE_10__ {char* data; } ;
typedef  TYPE_2__ svn_stringbuf_t ;
struct TYPE_11__ {int /*<<< orphan*/  len; int /*<<< orphan*/  data; } ;
typedef  TYPE_3__ svn_string_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SVN_UTF_UTON_XLATE_HANDLE ; 
 char* apr_pstrmemdup (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * check_non_ascii (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * check_utf8 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * convert_to_stringbuf (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_2__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  get_uton_xlate_handle_node (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  put_xlate_handle_node (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * svn_error_compose_create (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

svn_error_t *
svn_utf_cstring_from_utf8_string(const char **dest,
                                 const svn_string_t *src,
                                 apr_pool_t *pool)
{
  xlate_handle_node_t *node;
  svn_error_t *err;

  SVN_ERR(get_uton_xlate_handle_node(&node, pool));

  if (node->handle)
    {
      err = check_utf8(src->data, src->len, pool);
      if (! err)
        {
          svn_stringbuf_t *dbuf;

          err = convert_to_stringbuf(node, src->data, src->len,
                                     &dbuf, pool);
          if (! err)
            *dest = dbuf->data;
        }
    }
  else
    {
      err = check_non_ascii(src->data, src->len, pool);
      if (! err)
        *dest = apr_pstrmemdup(pool, src->data, src->len);
    }

  err = svn_error_compose_create(
          err,
          put_xlate_handle_node(node, SVN_UTF_UTON_XLATE_HANDLE, pool));

  return err;
}