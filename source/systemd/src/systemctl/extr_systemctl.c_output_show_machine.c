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

/* Variables and functions */
 int /*<<< orphan*/  FNM_NOESCAPE ; 
 int strv_fnmatch_or_empty (char**,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool output_show_machine(const char *name, char **patterns) {
        return strv_fnmatch_or_empty(patterns, name, FNM_NOESCAPE);
}