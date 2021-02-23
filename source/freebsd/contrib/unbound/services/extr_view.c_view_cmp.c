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
struct view {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int 
view_cmp(const void* v1, const void* v2)
{
	struct view* a = (struct view*)v1;
	struct view* b = (struct view*)v2;
	
	return strcmp(a->name, b->name);
}