#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  TableCell ;
typedef  int /*<<< orphan*/  Table ;
struct TYPE_2__ {unsigned int align_percent; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int table_dedup_cell (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_1__* table_get_data (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int table_set_align_percent(Table *t, TableCell *cell, unsigned percent) {
        int r;

        assert(t);
        assert(cell);

        if (percent == (unsigned) -1)
                percent = 0;

        assert(percent <= 100);

        r = table_dedup_cell(t, cell);
        if (r < 0)
                return r;

        table_get_data(t, cell)->align_percent = percent;
        return 0;
}