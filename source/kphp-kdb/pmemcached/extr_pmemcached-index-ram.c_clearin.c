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
 scalar_t__ BUFFSIZE ; 
 scalar_t__ Buff ; 
 scalar_t__ rptr ; 
 scalar_t__ wptr ; 
 scalar_t__ wptr0 ; 

void clearin (void) {
  rptr = wptr = wptr0 = Buff + BUFFSIZE;
}