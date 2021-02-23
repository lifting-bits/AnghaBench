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
typedef  int /*<<< orphan*/  hb_value_t ;
typedef  int /*<<< orphan*/  hb_value_array_t ;

/* Variables and functions */
 int /*<<< orphan*/  json_array_insert_new (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 

void
hb_value_array_insert(hb_value_array_t *array, int index, hb_value_t *value)
{
    json_array_insert_new(array, index, value);
}