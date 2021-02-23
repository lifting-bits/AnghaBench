#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  repo_mgr; int /*<<< orphan*/  seaf_dir; } ;
struct TYPE_4__ {int /*<<< orphan*/  message; } ;
typedef  TYPE_1__ GError ;
typedef  int /*<<< orphan*/  GDir ;

/* Variables and functions */
 char* g_build_filename (int /*<<< orphan*/ ,char*,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_dir_close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * g_dir_open (char*,int /*<<< orphan*/ ,TYPE_1__**) ; 
 char* g_dir_read_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_free (char*) ; 
 int /*<<< orphan*/  is_repo_store_in_use (char const*) ; 
 TYPE_2__* seaf ; 
 int /*<<< orphan*/  seaf_message (char*,char const*,char const*) ; 
 int /*<<< orphan*/  seaf_repo_manager_move_repo_store (int /*<<< orphan*/ ,char const*,char const*) ; 
 int /*<<< orphan*/  seaf_warning (char*,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
cleanup_unused_repo_stores (const char *type)
{
    char *top_store_dir;
    const char *repo_id;

    top_store_dir = g_build_filename (seaf->seaf_dir, "storage", type, NULL);

    GError *error = NULL;
    GDir *dir = g_dir_open (top_store_dir, 0, &error);
    if (!dir) {
        seaf_warning ("Failed to open store dir %s: %s.\n",
                      top_store_dir, error->message);
        g_free (top_store_dir);
        return;
    }

    while ((repo_id = g_dir_read_name(dir)) != NULL) {
        if (!is_repo_store_in_use (repo_id)) {
            seaf_message ("Moving %s for deleted repo %s.\n", type, repo_id);
            seaf_repo_manager_move_repo_store (seaf->repo_mgr, type, repo_id);
        }
    }

    g_free (top_store_dir);
    g_dir_close (dir);
}