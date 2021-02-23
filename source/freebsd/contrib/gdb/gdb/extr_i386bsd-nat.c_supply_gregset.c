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
typedef  int /*<<< orphan*/  gregset_t ;

/* Variables and functions */
 scalar_t__ CANNOT_FETCH_REGISTER (int) ; 
 int I386_NUM_GREGS ; 
 int /*<<< orphan*/ * REG_ADDR (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  supply_register (int,int /*<<< orphan*/ *) ; 

void
supply_gregset (gregset_t *gregsetp)
{
  int i;

  for (i = 0; i < I386_NUM_GREGS; i++)
    {
      if (CANNOT_FETCH_REGISTER (i))
	supply_register (i, NULL);
      else
	supply_register (i, REG_ADDR (gregsetp, i));
    }
}