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
struct tm6000_fh {int dummy; } ;
struct tm6000_core {struct tm6000_fh* resources; } ;

/* Variables and functions */
 int /*<<< orphan*/  V4L2_DEBUG_RES_LOCK ; 
 int /*<<< orphan*/  dprintk (struct tm6000_core*,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void res_free(struct tm6000_core *dev, struct tm6000_fh *fh)
{
	/* Is the current fh handling it? if so, that's OK */
	if (dev->resources != fh)
		return;

	dev->resources = NULL;
	dprintk(dev, V4L2_DEBUG_RES_LOCK, "res: put\n");
}