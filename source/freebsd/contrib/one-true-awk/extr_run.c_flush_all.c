#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ fp; } ;

/* Variables and functions */
 int /*<<< orphan*/  fflush (scalar_t__) ; 
 TYPE_1__* files ; 
 int nfiles ; 

void flush_all(void)
{
	int i;

	for (i = 0; i < nfiles; i++)
		if (files[i].fp)
			fflush(files[i].fp);
}