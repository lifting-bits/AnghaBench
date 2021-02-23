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

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 unsigned long HWREG (scalar_t__) ; 
 unsigned long TIMER_A ; 
 unsigned long TIMER_B ; 
 scalar_t__ TIMER_O_TAILR ; 
 scalar_t__ TIMER_O_TBILR ; 
 int TimerBaseValid (unsigned long) ; 

unsigned long
TimerLoadGet(unsigned long ulBase, unsigned long ulTimer)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B));

    //
    // Return the appropriate load value.
    //
    return((ulTimer == TIMER_A) ? HWREG(ulBase + TIMER_O_TAILR) :
           HWREG(ulBase + TIMER_O_TBILR));
}