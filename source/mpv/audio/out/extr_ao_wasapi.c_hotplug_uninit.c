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
struct ao {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CoUninitialize () ; 
 int /*<<< orphan*/  MP_DBG (struct ao*,char*) ; 
 int /*<<< orphan*/  wasapi_change_uninit (struct ao*) ; 

__attribute__((used)) static void hotplug_uninit(struct ao *ao)
{
    MP_DBG(ao, "Hotplug uninit\n");
    wasapi_change_uninit(ao);
    CoUninitialize();
}