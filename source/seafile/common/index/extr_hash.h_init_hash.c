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
struct hash_table {int /*<<< orphan*/ * array; scalar_t__ nr; scalar_t__ size; } ;

/* Variables and functions */

__attribute__((used)) static inline void init_hash(struct hash_table *table)
{
    table->size = 0;
    table->nr = 0;
    table->array = NULL;
}