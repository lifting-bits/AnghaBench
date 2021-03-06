#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct matrox_fb_info {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  default_value; } ;
struct TYPE_4__ {TYPE_1__ desc; } ;

/* Variables and functions */
 unsigned int G450CTRLS ; 
 TYPE_2__* g450_controls ; 
 int /*<<< orphan*/ * get_ctrl_ptr (struct matrox_fb_info*,unsigned int) ; 

__attribute__((used)) static void tvo_fill_defaults(struct matrox_fb_info *minfo)
{
	unsigned int i;
	
	for (i = 0; i < G450CTRLS; i++) {
		*get_ctrl_ptr(minfo, i) = g450_controls[i].desc.default_value;
	}
}