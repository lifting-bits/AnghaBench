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
struct TYPE_2__ {int /*<<< orphan*/  (* DeInit ) () ;} ;

/* Variables and functions */
 TYPE_1__* CurPer ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  stub1 () ; 
 int testspassed ; 

void cleanup(void)
{	
	if (CurPer)
	{
      CurPer->DeInit();
      testspassed++;
		printf("Test Score: %d/11 \n", testspassed);
	}
}