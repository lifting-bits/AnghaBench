#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {TYPE_2__* _str; } ;
struct TYPE_9__ {TYPE_1__ val; } ;
struct TYPE_8__ {int /*<<< orphan*/  len; int /*<<< orphan*/  data; } ;
typedef  TYPE_2__ DsoJsonStr ;
typedef  TYPE_3__ DsoJsonObj ;

/* Variables and functions */
 int /*<<< orphan*/  allocDsoStr (TYPE_2__*,unsigned int) ; 
 TYPE_3__* dso_json_str_new () ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 

DsoJsonObj * dso_json_str_new_from_str_len (const char *str, unsigned int len) {
	DsoJsonObj *x = dso_json_str_new ();
	if (!x) return NULL;
	DsoJsonStr * dsoStr = x->val._str;
	allocDsoStr (dsoStr, len);
	memcpy (dsoStr->data, str, dsoStr->len);
	return x;
}