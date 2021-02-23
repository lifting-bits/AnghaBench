#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* _list; } ;
struct TYPE_7__ {TYPE_2__ val; } ;
struct TYPE_5__ {int /*<<< orphan*/ * json_list; } ;
typedef  TYPE_3__ DsoJsonObj ;

/* Variables and functions */
 int /*<<< orphan*/  r_list_free (int /*<<< orphan*/ *) ; 

void dso_json_list_free (DsoJsonObj *x) {
	if (!x) return;
	if (x->val._list && x->val._list->json_list) {
		r_list_free (x->val._list->json_list);
		x->val._list->json_list = NULL;
	}
}