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
typedef  int /*<<< orphan*/  json_t ;
struct TYPE_3__ {size_t entries; int /*<<< orphan*/ * table; } ;
typedef  TYPE_1__ json_array_t ;

/* Variables and functions */
 int /*<<< orphan*/  json_decref (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  json_is_array (int /*<<< orphan*/ *) ; 
 TYPE_1__* json_to_array (int /*<<< orphan*/ *) ; 

int json_array_clear(json_t *json)
{
    json_array_t *array;
    size_t i;

    if(!json_is_array(json))
        return -1;
    array = json_to_array(json);

    for(i = 0; i < array->entries; i++)
        json_decref(array->table[i]);

    array->entries = 0;
    return 0;
}