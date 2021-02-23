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
typedef  int /*<<< orphan*/  SearpcClient ;
typedef  int /*<<< orphan*/  GError ;

/* Variables and functions */
 int /*<<< orphan*/  g_return_val_if_fail (int /*<<< orphan*/ ,int) ; 
 int searpc_client_call__int (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ **,int,char*,char const*,char*,char const*,char*,char const*) ; 

int
seafile_set_repo_property (SearpcClient *client,
                           const char *repo_id,
                           const char *key,
                           const char *value,
                           GError **error)
{
    g_return_val_if_fail (client && repo_id && key, -1);

    return searpc_client_call__int (
        client, "seafile_set_repo_property", error,
        3, "string", repo_id, "string", key, "string", value);
}