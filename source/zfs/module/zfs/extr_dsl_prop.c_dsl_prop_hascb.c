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
struct TYPE_3__ {int /*<<< orphan*/  ds_prop_cbs; } ;
typedef  TYPE_1__ dsl_dataset_t ;
typedef  int boolean_t ;

/* Variables and functions */
 int /*<<< orphan*/  list_is_empty (int /*<<< orphan*/ *) ; 

boolean_t
dsl_prop_hascb(dsl_dataset_t *ds)
{
	return (!list_is_empty(&ds->ds_prop_cbs));
}