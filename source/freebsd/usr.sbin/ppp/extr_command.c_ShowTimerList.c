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
struct cmdargs {int /*<<< orphan*/  prompt; } ;

/* Variables and functions */
 int /*<<< orphan*/  timer_Show (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ShowTimerList(struct cmdargs const *arg)
{
  timer_Show(0, arg->prompt);
  return 0;
}