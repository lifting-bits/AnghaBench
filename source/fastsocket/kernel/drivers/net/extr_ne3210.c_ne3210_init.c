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
 int eisa_driver_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ne3210_eisa_driver ; 

__attribute__((used)) static int ne3210_init(void)
{
	return eisa_driver_register (&ne3210_eisa_driver);
}