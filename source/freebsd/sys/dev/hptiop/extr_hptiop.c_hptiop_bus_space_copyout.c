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
typedef  int /*<<< orphan*/  u_int8_t ;
typedef  scalar_t__ u_int32_t ;
struct hpt_iop_hba {int /*<<< orphan*/  bar0h; int /*<<< orphan*/  bar0t; } ;

/* Variables and functions */
 unsigned char bus_space_read_1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ copyout (unsigned char*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int hptiop_bus_space_copyout(struct hpt_iop_hba *hba, u_int32_t bus,
									void *user, int size)
{
	unsigned char byte;
	int i;

	for (i=0; i<size; i++) {
		byte = bus_space_read_1(hba->bar0t, hba->bar0h, bus + i);
		if (copyout(&byte, (u_int8_t *)user + i, 1))
			return -1;
	}

	return 0;
}