#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ kb_data; } ;
typedef  TYPE_1__ keyboard_t ;
struct TYPE_5__ {int /*<<< orphan*/  kbdc; } ;
typedef  TYPE_2__ atkbd_state_t ;

/* Variables and functions */
 int kbdc_lock (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
atkbd_lock(keyboard_t *kbd, int lock)
{
	return kbdc_lock(((atkbd_state_t *)kbd->kb_data)->kbdc, lock);
}