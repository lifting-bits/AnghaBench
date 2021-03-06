#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {unsigned short base; int mode; } ;
typedef  TYPE_1__ imm_struct ;

/* Variables and functions */
 int /*<<< orphan*/  DID_ERROR ; 
#define  IMM_EPP_16 132 
#define  IMM_EPP_32 131 
#define  IMM_EPP_8 130 
#define  IMM_NIBBLE 129 
#define  IMM_PS2 128 
 int /*<<< orphan*/  ecp_sync (TYPE_1__*) ; 
 int /*<<< orphan*/  epp_reset (unsigned short) ; 
 int imm_byte_in (unsigned short,char*,int) ; 
 int /*<<< orphan*/  imm_fail (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int imm_nibble_in (unsigned short,char*,int) ; 
 int imm_wait (TYPE_1__*) ; 
 int /*<<< orphan*/  insb (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  insl (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  insw (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  printk (char*) ; 
 int r_str (unsigned short) ; 
 int /*<<< orphan*/  w_ctr (unsigned short,int) ; 

__attribute__((used)) static int imm_in(imm_struct *dev, char *buffer, int len)
{
	unsigned short ppb = dev->base;
	int r = imm_wait(dev);

	/*
	 * Make sure that:
	 * a) the SCSI bus is BUSY (device still listening)
	 * b) the device is sending data
	 */
	if ((r & 0x18) != 0x18) {
		imm_fail(dev, DID_ERROR);
		return 0;
	}
	switch (dev->mode) {
	case IMM_NIBBLE:
		/* 4 bit input, with a loop */
		r = imm_nibble_in(ppb, buffer, len);
		w_ctr(ppb, 0xc);
		break;

	case IMM_PS2:
		/* 8 bit input, with a loop */
		r = imm_byte_in(ppb, buffer, len);
		w_ctr(ppb, 0xc);
		break;

	case IMM_EPP_32:
	case IMM_EPP_16:
	case IMM_EPP_8:
		epp_reset(ppb);
		w_ctr(ppb, 0x24);
#ifdef CONFIG_SCSI_IZIP_EPP16
		if (!(((long) buffer | len) & 0x01))
			insw(ppb + 4, buffer, len >> 1);
#else
		if (!(((long) buffer | len) & 0x03))
			insl(ppb + 4, buffer, len >> 2);
#endif
		else
			insb(ppb + 4, buffer, len);
		w_ctr(ppb, 0x2c);
		r = !(r_str(ppb) & 0x01);
		w_ctr(ppb, 0x2c);
		ecp_sync(dev);
		break;

	default:
		printk("IMM: bug in imm_ins()\n");
		r = 0;
		break;
	}
	return r;
}