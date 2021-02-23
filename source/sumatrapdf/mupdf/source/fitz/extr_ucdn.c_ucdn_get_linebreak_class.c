#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_2__ {int linebreak_class; } ;

/* Variables and functions */
 TYPE_1__* get_ucd_record (int /*<<< orphan*/ ) ; 

int ucdn_get_linebreak_class(uint32_t code)
{
	return get_ucd_record(code)->linebreak_class;
}