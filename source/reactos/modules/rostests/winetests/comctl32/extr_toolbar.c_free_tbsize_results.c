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
struct TYPE_3__ {struct TYPE_3__* prcButtons; } ;

/* Variables and functions */
 int /*<<< orphan*/  heap_free (TYPE_1__*) ; 
 TYPE_1__* tbsize_results ; 
 int tbsize_results_num ; 

__attribute__((used)) static void free_tbsize_results(void) {
    int i;

    for (i = 0; i < tbsize_results_num; i++)
        heap_free(tbsize_results[i].prcButtons);
    heap_free(tbsize_results);
    tbsize_results = NULL;
}