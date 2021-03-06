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
typedef  int u32 ;
struct ace_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ace_out (struct ace_device*,int,int) ; 

__attribute__((used)) static inline void ace_out32(struct ace_device *ace, int reg, u32 val)
{
	ace_out(ace, reg, val);
	ace_out(ace, reg + 2, val >> 16);
}