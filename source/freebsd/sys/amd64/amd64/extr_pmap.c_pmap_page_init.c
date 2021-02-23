#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_2__* vm_page_t ;
struct TYPE_4__ {int /*<<< orphan*/  pat_mode; int /*<<< orphan*/  pv_list; } ;
struct TYPE_5__ {TYPE_1__ md; } ;

/* Variables and functions */
 int /*<<< orphan*/  PAT_WRITE_BACK ; 
 int /*<<< orphan*/  TAILQ_INIT (int /*<<< orphan*/ *) ; 

void
pmap_page_init(vm_page_t m)
{

	TAILQ_INIT(&m->md.pv_list);
	m->md.pat_mode = PAT_WRITE_BACK;
}