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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int mchip_mmregs; } ;

/* Variables and functions */
 int /*<<< orphan*/  mchip_sync (int) ; 
 TYPE_1__ meye ; 
 int /*<<< orphan*/  readl (int) ; 

__attribute__((used)) static inline u32 mchip_read(int reg)
{
	mchip_sync(reg);
	return readl(meye.mchip_mmregs + reg);
}