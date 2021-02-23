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
 int /*<<< orphan*/  FORKEE_ASSERT_EQ (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SIGINT ; 
 int /*<<< orphan*/  traceme2_caught ; 

__attribute__((used)) static void
traceme2_sighandler(int sig)
{
	FORKEE_ASSERT_EQ(sig, SIGINT);

	++traceme2_caught;
}