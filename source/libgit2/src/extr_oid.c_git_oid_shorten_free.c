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
struct TYPE_4__ {struct TYPE_4__* nodes; } ;
typedef  TYPE_1__ git_oid_shorten ;

/* Variables and functions */
 int /*<<< orphan*/  git__free (TYPE_1__*) ; 

void git_oid_shorten_free(git_oid_shorten *os)
{
	if (os == NULL)
		return;

	git__free(os->nodes);
	git__free(os);
}