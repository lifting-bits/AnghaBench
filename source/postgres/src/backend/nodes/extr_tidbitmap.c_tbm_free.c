#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {struct TYPE_4__* schunks; struct TYPE_4__* spages; scalar_t__ pagetable; } ;
typedef  TYPE_1__ TIDBitmap ;

/* Variables and functions */
 int /*<<< orphan*/  pagetable_destroy (scalar_t__) ; 
 int /*<<< orphan*/  pfree (TYPE_1__*) ; 

void
tbm_free(TIDBitmap *tbm)
{
	if (tbm->pagetable)
		pagetable_destroy(tbm->pagetable);
	if (tbm->spages)
		pfree(tbm->spages);
	if (tbm->schunks)
		pfree(tbm->schunks);
	pfree(tbm);
}