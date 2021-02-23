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
 int /*<<< orphan*/  fputs (char*,int /*<<< orphan*/ ) ; 
 int max_cols ; 
 int /*<<< orphan*/  putchar (char) ; 
 int /*<<< orphan*/  stdout ; 

__attribute__((used)) static void
write_tabs(int *tab_list)
{
    int stop;

    while ((stop = *tab_list++) > 0 && stop <= max_cols) {
	fputs((stop == 1) ? "*" : "\t*", stdout);
    };
    /* also show a tab _past_ the stops */
    if (stop < max_cols)
	fputs("\t+", stdout);
    putchar('\n');
}