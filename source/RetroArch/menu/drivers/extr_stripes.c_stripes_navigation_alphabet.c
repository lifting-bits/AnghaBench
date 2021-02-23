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
typedef  int /*<<< orphan*/  stripes_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  stripes_selection_pointer_changed (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void stripes_navigation_alphabet(void *data, size_t *unused)
{
   stripes_handle_t  *stripes  = (stripes_handle_t*)data;
   stripes_selection_pointer_changed(stripes, true);
}