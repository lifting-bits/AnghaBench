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
typedef  int /*<<< orphan*/  CMatchFinder ;

/* Variables and functions */
 int /*<<< orphan*/  MatchFinder_Init_3 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MatchFinder_Init_HighHash (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  MatchFinder_Init_LowHash (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  True ; 

void MatchFinder_Init(CMatchFinder *p)
{
  MatchFinder_Init_HighHash(p);
  MatchFinder_Init_LowHash(p);
  MatchFinder_Init_3(p, True);
}