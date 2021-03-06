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
struct ath_hal {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/ * ah_eeprom; } ;
typedef  int /*<<< orphan*/  HAL_EEPROM_v1 ;

/* Variables and functions */
 int /*<<< orphan*/ * AH_NULL ; 
 TYPE_1__* AH_PRIVATE (struct ath_hal*) ; 
 int /*<<< orphan*/  ath_hal_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
v1EepromDetach(struct ath_hal *ah)
{
	HAL_EEPROM_v1 *ee = AH_PRIVATE(ah)->ah_eeprom;

	ath_hal_free(ee);
	AH_PRIVATE(ah)->ah_eeprom = AH_NULL;
}