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
typedef  int /*<<< orphan*/  UINT64 ;
typedef  int /*<<< orphan*/  UINT ;
typedef  int /*<<< orphan*/  JSON_OBJECT ;

/* Variables and functions */
 int /*<<< orphan*/  JsonNewNumber (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  JsonSet (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 

UINT JsonSetNumber(JSON_OBJECT *object, char *name, UINT64 number) {
	return JsonSet(object, name, JsonNewNumber(number));
}