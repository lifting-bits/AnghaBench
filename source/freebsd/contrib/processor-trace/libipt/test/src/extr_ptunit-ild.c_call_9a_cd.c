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
typedef  int uint8_t ;
struct ptunit_result {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PTI_INST_CALL_9A ; 
 int /*<<< orphan*/  ptem_16bit ; 
 int /*<<< orphan*/  ptu_classify_s (int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result call_9a_cd(void)
{
	uint8_t insn[] = { 0x9a, 0x00, 0x00, 0x00, 0x00 };

	ptu_classify_s(insn, ptem_16bit, PTI_INST_CALL_9A);

	return ptu_passed();
}