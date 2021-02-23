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
struct recvbuf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  read_peervars () ; 
 int /*<<< orphan*/  read_sysvars () ; 
 scalar_t__ res_associd ; 

__attribute__((used)) static void
read_variables(
	struct recvbuf *rbufp,
	int restrict_mask
	)
{
	if (res_associd)
		read_peervars();
	else
		read_sysvars();
}