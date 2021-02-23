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
typedef  int /*<<< orphan*/  svn_fs_x__id_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  apr_hash_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SVN_ERR_FS_CORRUPT ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/ * svn_error_createf (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  svn_fs_x__id_parse (int /*<<< orphan*/ *,char const*) ; 
 char* svn_hash_gets (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static svn_error_t *
read_id_part(svn_fs_x__id_t *id,
             apr_hash_t *headers,
             const char *header_name)
{
  const char *value = svn_hash_gets(headers, header_name);
  if (value == NULL)
    return svn_error_createf(SVN_ERR_FS_CORRUPT, NULL,
                             _("Missing %s field in node-rev"),
                             header_name);

  SVN_ERR(svn_fs_x__id_parse(id, value));
  return SVN_NO_ERROR;
}