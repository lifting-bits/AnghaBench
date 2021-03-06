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
struct TYPE_2__ {unsigned int* slot; } ;

/* Variables and functions */
 unsigned int LSCSA_QW_OFFSET (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPU_WrOutIntrMbox ; 
 int /*<<< orphan*/  ppuint_mb ; 
 TYPE_1__* regs_spill ; 
 int /*<<< orphan*/  spu_writech (int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static inline void write_ppuint_mb(void)
{
	unsigned int offset;
	unsigned int data;

	/* Restore, Step 12:
	 *    Write the MFC_WrInt_MB channel with the PPUINT_MB
	 *    data from LSCSA.
	 */
	offset = LSCSA_QW_OFFSET(ppuint_mb);
	data = regs_spill[offset].slot[0];
	spu_writech(SPU_WrOutIntrMbox, data);
}