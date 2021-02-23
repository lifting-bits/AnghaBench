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
typedef  int /*<<< orphan*/  wiiu_hid_t ;

/* Variables and functions */
 int /*<<< orphan*/  RARCH_LOG (char*) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void delete_hid(wiiu_hid_t *hid)
{
   RARCH_LOG("[hid]: delete_hid()\n");
   if (hid)
      free(hid);
}