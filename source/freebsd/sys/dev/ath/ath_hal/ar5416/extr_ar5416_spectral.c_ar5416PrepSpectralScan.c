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
struct ath_hal {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AR_PHY_ERR ; 
 int /*<<< orphan*/  ENABLE_ALL_PHYERR ; 
 int /*<<< orphan*/  OS_REG_WRITE (struct ath_hal*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ar5416DisableRadar (struct ath_hal*) ; 

__attribute__((used)) static void
ar5416PrepSpectralScan(struct ath_hal *ah)
{

	ar5416DisableRadar(ah);
	OS_REG_WRITE(ah, AR_PHY_ERR, ENABLE_ALL_PHYERR);
}