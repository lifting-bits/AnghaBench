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
struct klp_patch {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __klp_free_objects (struct klp_patch*,int) ; 

__attribute__((used)) static void klp_free_objects(struct klp_patch *patch)
{
	__klp_free_objects(patch, false);
}