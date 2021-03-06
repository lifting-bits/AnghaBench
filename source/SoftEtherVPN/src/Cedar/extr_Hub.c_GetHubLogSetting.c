#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  LogSetting; } ;
typedef  int /*<<< orphan*/  HUB_LOG ;
typedef  TYPE_1__ HUB ;

/* Variables and functions */
 int /*<<< orphan*/  Copy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

void GetHubLogSetting(HUB *h, HUB_LOG *setting)
{
	// Validate arguments
	if (setting == NULL || h == NULL)
	{
		return;
	}

	Copy(setting, &h->LogSetting, sizeof(HUB_LOG));
}