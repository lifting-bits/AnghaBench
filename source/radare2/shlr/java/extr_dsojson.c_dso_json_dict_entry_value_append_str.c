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
typedef  int /*<<< orphan*/  DsoJsonObj ;

/* Variables and functions */
 int dso_json_dict_entry_value_append_obj (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ dso_json_is_dict_entry (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dso_json_obj_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * dso_json_str_new_from_str (char*) ; 

int dso_json_dict_entry_value_append_str (DsoJsonObj *entry_obj, char *str) {
	int res = false;
	if (dso_json_is_dict_entry (entry_obj)) {
		DsoJsonObj *o_str = dso_json_str_new_from_str (str);
		res = dso_json_dict_entry_value_append_obj (entry_obj, o_str);
		if (!res) dso_json_obj_del (o_str);
	}
	return res;
}