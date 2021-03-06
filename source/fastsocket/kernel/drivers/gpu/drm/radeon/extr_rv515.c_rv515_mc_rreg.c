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
typedef  int uint32_t ;
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MC_IND_DATA ; 
 int /*<<< orphan*/  MC_IND_INDEX ; 
 int RREG32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int) ; 

uint32_t rv515_mc_rreg(struct radeon_device *rdev, uint32_t reg)
{
	uint32_t r;

	WREG32(MC_IND_INDEX, 0x7f0000 | (reg & 0xffff));
	r = RREG32(MC_IND_DATA);
	WREG32(MC_IND_INDEX, 0);
	return r;
}