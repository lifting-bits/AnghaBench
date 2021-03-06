#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {char* string; } ;
struct TYPE_6__ {TYPE_1__ value; } ;
typedef  TYPE_2__ JSON_VALUE ;

/* Variables and functions */
 scalar_t__ JSON_TYPE_STRING ; 
 scalar_t__ JsonValueGetType (TYPE_2__*) ; 

char * JsonValueGetStr(JSON_VALUE *value) {
	return JsonValueGetType(value) == JSON_TYPE_STRING ? value->value.string : NULL;
}