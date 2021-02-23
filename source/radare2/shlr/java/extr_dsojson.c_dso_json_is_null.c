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
 scalar_t__ DSO_JSON_NULL ; 
 scalar_t__ get_type (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int dso_json_is_null (DsoJsonObj *y) {
	return get_type (y) == DSO_JSON_NULL;
}