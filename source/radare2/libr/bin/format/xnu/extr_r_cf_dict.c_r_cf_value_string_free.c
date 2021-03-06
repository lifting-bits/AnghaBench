#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  type; struct TYPE_4__* value; } ;
typedef  TYPE_1__ RCFValueString ;

/* Variables and functions */
 int /*<<< orphan*/  R_CF_INVALID ; 
 int /*<<< orphan*/  R_FREE (TYPE_1__*) ; 

__attribute__((used)) static void r_cf_value_string_free(RCFValueString *string) {
	if (!string) {
		return;
	}

	if (string->value) {
		R_FREE (string->value);
	}

	string->type = R_CF_INVALID;
	R_FREE (string);
}