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
typedef  int /*<<< orphan*/  u32 ;
struct lanai_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IntStatusMasked_Reg ; 
 int /*<<< orphan*/  reg_read (struct lanai_dev const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 intr_pending(const struct lanai_dev *lanai)
{
	return reg_read(lanai, IntStatusMasked_Reg);
}