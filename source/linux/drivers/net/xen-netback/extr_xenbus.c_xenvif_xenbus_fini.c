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
 int /*<<< orphan*/  netback_driver ; 
 void xenbus_unregister_driver (int /*<<< orphan*/ *) ; 

void xenvif_xenbus_fini(void)
{
	return xenbus_unregister_driver(&netback_driver);
}