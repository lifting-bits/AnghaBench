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
struct st_h2o_hpack_header_table_entry_t {int /*<<< orphan*/  value; int /*<<< orphan*/  name; } ;
struct TYPE_3__ {scalar_t__ num_entries; size_t entry_start_index; size_t entry_capacity; struct st_h2o_hpack_header_table_entry_t* entries; } ;
typedef  TYPE_1__ h2o_hpack_header_table_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct st_h2o_hpack_header_table_entry_t*) ; 
 int /*<<< orphan*/  h2o_iovec_is_token (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  h2o_mem_release_shared (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  value_is_part_of_static_table (int /*<<< orphan*/ ) ; 

void h2o_hpack_dispose_header_table(h2o_hpack_header_table_t *header_table)
{
    if (header_table->num_entries != 0) {
        size_t index = header_table->entry_start_index;
        do {
            struct st_h2o_hpack_header_table_entry_t *entry = header_table->entries + index;
            if (!h2o_iovec_is_token(entry->name))
                h2o_mem_release_shared(entry->name);
            if (!value_is_part_of_static_table(entry->value))
                h2o_mem_release_shared(entry->value);
            index = (index + 1) % header_table->entry_capacity;
        } while (--header_table->num_entries != 0);
    }
    free(header_table->entries);
}