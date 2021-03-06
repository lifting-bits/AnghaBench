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
struct net_device {int dummy; } ;
typedef  int /*<<< orphan*/  RESET_TYPE ;

/* Variables and functions */
 int /*<<< orphan*/  COMP_RESET ; 
 scalar_t__ HalRxCheckStuck8190Pci (struct net_device*) ; 
 int /*<<< orphan*/  RESET_TYPE_NORESET ; 
 int /*<<< orphan*/  RESET_TYPE_SILENT ; 
 int /*<<< orphan*/  RT_TRACE (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static RESET_TYPE RxCheckStuck(struct net_device *dev)
{

	if(HalRxCheckStuck8190Pci(dev))
	{
		RT_TRACE(COMP_RESET, "RxStuck Condition\n");
		return RESET_TYPE_SILENT;
	}

	return RESET_TYPE_NORESET;
}