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
 int /*<<< orphan*/  MFI_DCMD_CFG_FOREIGN_DISPLAY ; 
 int display_format (int,char**,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
foreign_display(int ac, char **av)
{
	return(display_format(ac, av, 1/*diagnostic output*/, MFI_DCMD_CFG_FOREIGN_DISPLAY));
}