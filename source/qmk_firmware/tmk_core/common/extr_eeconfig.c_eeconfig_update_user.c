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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  EECONFIG_USER ; 
 int /*<<< orphan*/  eeprom_update_dword (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void eeconfig_update_user(uint32_t val) { eeprom_update_dword(EECONFIG_USER, val); }