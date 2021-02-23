#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  settings; int /*<<< orphan*/  builder; } ;
typedef  TYPE_1__ signal_user_data_t ;
typedef  int gint ;
typedef  scalar_t__ gboolean ;
typedef  int /*<<< orphan*/  GtkTreeView ;
typedef  int /*<<< orphan*/  GtkTreeSelection ;
typedef  int /*<<< orphan*/  GtkTreePath ;
typedef  int /*<<< orphan*/  GtkTreeModel ;
typedef  int /*<<< orphan*/  GtkTreeIter ;
typedef  int /*<<< orphan*/  GhbValue ;

/* Variables and functions */
 int /*<<< orphan*/  GHB_WIDGET (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * GTK_TREE_VIEW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ghb_array_get (int /*<<< orphan*/ *,int) ; 
 int ghb_array_len (int /*<<< orphan*/ *) ; 
 scalar_t__ ghb_dict_get_bool (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * ghb_get_job_subtitle_list (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ghb_get_job_subtitle_search (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * gtk_tree_model_get_path (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_tree_path_free (int /*<<< orphan*/ *) ; 
 int* gtk_tree_path_get_indices (int /*<<< orphan*/ *) ; 
 scalar_t__ gtk_tree_selection_get_selected (int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * gtk_tree_view_get_selection (int /*<<< orphan*/ *) ; 

__attribute__((used)) static GhbValue*
subtitle_get_selected_settings(signal_user_data_t *ud, int *index)
{
    GtkTreeView *tv;
    GtkTreeSelection *ts;
    GtkTreeModel *tm;
    GtkTreeIter iter;
    GhbValue *subsettings = NULL;

    tv = GTK_TREE_VIEW(GHB_WIDGET(ud->builder, "subtitle_list_view"));
    ts = gtk_tree_view_get_selection(tv);
    if (gtk_tree_selection_get_selected(ts, &tm, &iter))
    {
        GhbValue *subtitle_list, *subtitle_search;
        gboolean search;
        gint row, *indices;
        GtkTreePath *tp;

        // Get the row number
        tp = gtk_tree_model_get_path(tm, &iter);
        indices = gtk_tree_path_get_indices(tp);
        row = indices[0];
        gtk_tree_path_free(tp);

        subtitle_search = ghb_get_job_subtitle_search(ud->settings);
        search = ghb_dict_get_bool(subtitle_search, "Enable");
        if (search)
        {
            if (row == 0)
            {
                if (index != NULL)
                    *index = -1;
                return subtitle_search;
            }
            row--;
        }

        subtitle_list = ghb_get_job_subtitle_list(ud->settings);
        if (row < 0 || row >= ghb_array_len(subtitle_list))
            return NULL;

        subsettings = ghb_array_get(subtitle_list, row);
        if (index != NULL)
            *index = row;
    }
    return subsettings;
}