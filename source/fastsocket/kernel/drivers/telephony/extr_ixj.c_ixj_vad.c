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
typedef  int /*<<< orphan*/  IXJ ;

/* Variables and functions */
 int /*<<< orphan*/  ixj_WriteDSPCommand (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ixj_vad(IXJ *j, int arg)
{
	if (arg)
		ixj_WriteDSPCommand(0x513F, j);
	else
		ixj_WriteDSPCommand(0x513E, j);
}