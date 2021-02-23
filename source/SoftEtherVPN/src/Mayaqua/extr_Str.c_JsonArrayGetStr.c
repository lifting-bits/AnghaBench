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
typedef  int /*<<< orphan*/  UINT ;
typedef  int /*<<< orphan*/  JSON_ARRAY ;

/* Variables and functions */
 int /*<<< orphan*/  JsonArrayGet (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 char* JsonValueGetStr (int /*<<< orphan*/ ) ; 

char * JsonArrayGetStr(JSON_ARRAY *array, UINT index) {
	return JsonValueGetStr(JsonArrayGet(array, index));
}