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
struct TYPE_4__ {int /*<<< orphan*/  next; int /*<<< orphan*/  curr; } ;
typedef  TYPE_1__ inifile ;

/* Variables and functions */
 int /*<<< orphan*/  inifile_line_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pefree (TYPE_1__*,int) ; 

void inifile_free(inifile *dba, int persistent)
{
	if (dba) {
		inifile_line_free(&dba->curr);
		inifile_line_free(&dba->next);
		pefree(dba, persistent);
	}
}