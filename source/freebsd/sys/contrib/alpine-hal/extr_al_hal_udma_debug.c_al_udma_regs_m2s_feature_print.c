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
struct al_udma {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AL_UDMA_PRINT_REG (struct al_udma*,char*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  al_dbg (char*) ; 
 int /*<<< orphan*/  m2s ; 
 int /*<<< orphan*/  m2s_feature ; 
 int /*<<< orphan*/  reg_1 ; 
 int /*<<< orphan*/  reg_3 ; 
 int /*<<< orphan*/  reg_4 ; 
 int /*<<< orphan*/  reg_5 ; 

__attribute__((used)) static void al_udma_regs_m2s_feature_print(struct al_udma *udma)
{
	al_dbg("M2S feature regs:\n");
	AL_UDMA_PRINT_REG(udma, " ", "\n", m2s, m2s_feature, reg_1);
	AL_UDMA_PRINT_REG(udma, " ", "\n", m2s, m2s_feature, reg_3);
	AL_UDMA_PRINT_REG(udma, " ", "\n", m2s, m2s_feature, reg_4);
	AL_UDMA_PRINT_REG(udma, " ", "\n", m2s, m2s_feature, reg_5);
}