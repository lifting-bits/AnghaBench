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

/* Variables and functions */
 int /*<<< orphan*/  YabLoadStateSlot (char*,int) ; 
 char* g_key_file_get_value (int /*<<< orphan*/ ,char*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  keyfile ; 

void YuiLoadState(void) {
  char * dir = g_key_file_get_value(keyfile, "General", "StatePath", NULL);

  YabLoadStateSlot(dir, 1);
}