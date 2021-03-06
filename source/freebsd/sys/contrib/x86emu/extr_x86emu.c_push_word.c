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
typedef  int /*<<< orphan*/  uint16_t ;
struct TYPE_2__ {int R_SP; int /*<<< orphan*/  R_SS; } ;
struct x86emu {TYPE_1__ x86; } ;

/* Variables and functions */
 int /*<<< orphan*/  store_word (struct x86emu*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void 
push_word(struct x86emu *emu, uint16_t w)
{
	emu->x86.R_SP -= 2;
	store_word(emu, emu->x86.R_SS, emu->x86.R_SP, w);
}