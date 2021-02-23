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
struct ctl_scsiio {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SSD_ELEM_NONE ; 
 int /*<<< orphan*/  SSD_KEY_DATA_PROTECT ; 
 int /*<<< orphan*/  ctl_set_sense (struct ctl_scsiio*,int,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 

void
ctl_set_hw_write_protected(struct ctl_scsiio *ctsio)
{
	/* "Hardware write protected" */
	ctl_set_sense(ctsio,
		      /*current_error*/ 1,
		      /*sense_key*/ SSD_KEY_DATA_PROTECT,
		      /*asc*/ 0x27,
		      /*ascq*/ 0x01,
		      SSD_ELEM_NONE);
}