#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * Read_Byte; } ;
typedef  TYPE_1__ c68k_struc ;
typedef  int /*<<< orphan*/  C68K_READ ;

/* Variables and functions */

void C68k_Set_ReadB(c68k_struc *cpu, C68K_READ *Func)
{
    cpu->Read_Byte = Func;
}