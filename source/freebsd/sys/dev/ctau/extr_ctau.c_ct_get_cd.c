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
struct TYPE_3__ {int /*<<< orphan*/  ST3; } ;
typedef  TYPE_1__ ct_chan_t ;

/* Variables and functions */
 int ST3_DCD_INV ; 
 int inb (int /*<<< orphan*/ ) ; 

int ct_get_cd (ct_chan_t *c)
{
	return (inb (c->ST3) & ST3_DCD_INV) == 0;
}