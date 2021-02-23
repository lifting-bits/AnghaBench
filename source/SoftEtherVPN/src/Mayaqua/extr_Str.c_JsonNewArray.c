#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  array; } ;
struct TYPE_7__ {TYPE_1__ value; int /*<<< orphan*/  type; int /*<<< orphan*/ * parent; } ;
typedef  TYPE_2__ JSON_VALUE ;

/* Variables and functions */
 int /*<<< orphan*/  JSON_TYPE_ARRAY ; 
 int /*<<< orphan*/  json_array_init (TYPE_2__*) ; 
 int /*<<< orphan*/  parson_free (TYPE_2__*) ; 
 scalar_t__ parson_malloc (int) ; 

JSON_VALUE * JsonNewArray(void) {
	JSON_VALUE *new_value = (JSON_VALUE*)parson_malloc(sizeof(JSON_VALUE));
	if (!new_value) {
		return NULL;
	}
	new_value->parent = NULL;
	new_value->type = JSON_TYPE_ARRAY;
	new_value->value.array = json_array_init(new_value);
	if (!new_value->value.array) {
		parson_free(new_value);
		return NULL;
	}
	return new_value;
}