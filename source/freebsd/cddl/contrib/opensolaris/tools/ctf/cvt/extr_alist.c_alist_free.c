#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  al_elements; } ;
typedef  TYPE_1__ alist_t ;

/* Variables and functions */
 int /*<<< orphan*/  alist_free_cb ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  hash_free (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 

void
alist_free(alist_t *alist)
{
	hash_free(alist->al_elements, alist_free_cb, alist);
	free(alist);
}