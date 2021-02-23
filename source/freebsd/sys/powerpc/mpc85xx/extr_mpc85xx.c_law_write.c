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
typedef  int uint64_t ;
typedef  int uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  OCP85XX_LAWBAR (int) ; 
 int /*<<< orphan*/  OCP85XX_LAWBARH (int) ; 
 int /*<<< orphan*/  OCP85XX_LAWBARL (int) ; 
 int /*<<< orphan*/  OCP85XX_LAWSR_85XX (int) ; 
 int /*<<< orphan*/  OCP85XX_LAWSR_QORIQ (int) ; 
 int /*<<< orphan*/  ccsr_read4 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ccsr_write4 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  isync () ; 
 scalar_t__ mpc85xx_is_qoriq () ; 

__attribute__((used)) static inline void
law_write(uint32_t n, uint64_t bar, uint32_t sr)
{

	if (mpc85xx_is_qoriq()) {
		ccsr_write4(OCP85XX_LAWBARH(n), bar >> 32);
		ccsr_write4(OCP85XX_LAWBARL(n), bar);
		ccsr_write4(OCP85XX_LAWSR_QORIQ(n), sr);
		ccsr_read4(OCP85XX_LAWSR_QORIQ(n));
	} else {
		ccsr_write4(OCP85XX_LAWBAR(n), bar >> 12);
		ccsr_write4(OCP85XX_LAWSR_85XX(n), sr);
		ccsr_read4(OCP85XX_LAWSR_85XX(n));
	}

	/*
	 * The last write to LAWAR should be followed by a read
	 * of LAWAR before any device try to use any of windows.
	 * What more the read of LAWAR should be followed by isync
	 * instruction.
	 */

	isync();
}