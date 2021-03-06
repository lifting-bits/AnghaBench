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
typedef  int u32 ;
struct ath_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AR_CR ; 
 int AR_CR_RXD ; 
 int /*<<< orphan*/  AR_DIAG_RX_DIS ; 
 int /*<<< orphan*/  AR_DIAG_SW ; 
 int /*<<< orphan*/  AR_DLCL_IFS (int) ; 
 int /*<<< orphan*/  AR_DRETRY_LIMIT (int) ; 
 int /*<<< orphan*/  AR_D_FPCTL ; 
 int /*<<< orphan*/  AR_D_GBL_IFS_EIFS ; 
 int /*<<< orphan*/  AR_D_GBL_IFS_SIFS ; 
 int AR_QMISC (int) ; 
 int AR_Q_MISC_DCU_EARLY_TERM_REQ ; 
 int /*<<< orphan*/  AR_TIME_OUT ; 
 int /*<<< orphan*/  REG_CLR_BIT (struct ath_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_SET_BIT (struct ath_hw*,int,int) ; 
 int /*<<< orphan*/  REG_WRITE (struct ath_hw*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void ar9002_hw_tx99_start(struct ath_hw *ah, u32 qnum)
{
	REG_SET_BIT(ah, 0x9864, 0x7f000);
	REG_SET_BIT(ah, 0x9924, 0x7f00fe);
	REG_CLR_BIT(ah, AR_DIAG_SW, AR_DIAG_RX_DIS);
	REG_WRITE(ah, AR_CR, AR_CR_RXD);
	REG_WRITE(ah, AR_DLCL_IFS(qnum), 0);
	REG_WRITE(ah, AR_D_GBL_IFS_SIFS, 20);
	REG_WRITE(ah, AR_D_GBL_IFS_EIFS, 20);
	REG_WRITE(ah, AR_D_FPCTL, 0x10|qnum);
	REG_WRITE(ah, AR_TIME_OUT, 0x00000400);
	REG_WRITE(ah, AR_DRETRY_LIMIT(qnum), 0xffffffff);
	REG_SET_BIT(ah, AR_QMISC(qnum), AR_Q_MISC_DCU_EARLY_TERM_REQ);
}