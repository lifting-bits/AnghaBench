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
struct TYPE_6__ {int ir; } ;
typedef  TYPE_1__ m68k_info ;

/* Variables and functions */
 int /*<<< orphan*/  LIMIT_CPU_TYPES (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  M68040_PLUS ; 
 int M68K_AM_REGI_ADDR_POST_INC ; 
 int /*<<< orphan*/  build_move16 (TYPE_1__*,int*,int*) ; 
 int read_imm_16 (TYPE_1__*) ; 

__attribute__((used)) static void d68040_move16_pi_pi(m68k_info *info)
{
	int data[] = { info->ir & 7, (read_imm_16(info) >> 12) & 7 };
	int modes[] = { M68K_AM_REGI_ADDR_POST_INC, M68K_AM_REGI_ADDR_POST_INC };

	LIMIT_CPU_TYPES(info, M68040_PLUS);

	build_move16(info, data, modes);
}