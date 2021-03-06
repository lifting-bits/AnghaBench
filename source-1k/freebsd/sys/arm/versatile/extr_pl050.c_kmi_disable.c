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
typedef  int /*<<< orphan*/  keyboard_t ;

/* Variables and functions */
 int /*<<< orphan*/  KBD_DEACTIVATE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KMI_LOCK () ; 
 int /*<<< orphan*/  KMI_UNLOCK () ; 

__attribute__((used)) static int
kmi_disable(keyboard_t *kbd)
{

	KMI_LOCK();
	KBD_DEACTIVATE(kbd);
	KMI_UNLOCK();

	return (0);
}