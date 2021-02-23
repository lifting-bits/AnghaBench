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
typedef  int /*<<< orphan*/  gboolean ;
typedef  int /*<<< orphan*/  GPatternSpec ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ g_pattern_match_string (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/ ** ignore_patterns ; 

gboolean
seaf_repo_manager_is_ignored_hidden_file (const char *filename)
{
    GPatternSpec **spec = ignore_patterns;

    while (*spec) {
        if (g_pattern_match_string(*spec, filename))
            return TRUE;
        spec++;
    }

    return FALSE;
}