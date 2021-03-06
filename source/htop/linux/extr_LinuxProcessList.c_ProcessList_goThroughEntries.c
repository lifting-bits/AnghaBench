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
struct timeval {int dummy; } ;
typedef  int /*<<< orphan*/  ProcessList ;
typedef  int /*<<< orphan*/  LinuxProcessList ;

/* Variables and functions */
 int /*<<< orphan*/  LinuxProcessList_recurseProcTree (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,double,struct timeval) ; 
 double LinuxProcessList_scanCPUTime (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LinuxProcessList_scanMemoryInfo (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PROCDIR ; 
 int /*<<< orphan*/  gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 

void ProcessList_goThroughEntries(ProcessList* super) {
   LinuxProcessList* this = (LinuxProcessList*) super;

   LinuxProcessList_scanMemoryInfo(super);
   double period = LinuxProcessList_scanCPUTime(this);

   struct timeval tv;
   gettimeofday(&tv, NULL);
   LinuxProcessList_recurseProcTree(this, PROCDIR, NULL, period, tv);
}