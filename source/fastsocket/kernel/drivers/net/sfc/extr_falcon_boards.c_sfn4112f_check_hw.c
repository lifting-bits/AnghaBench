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
struct efx_nic {int dummy; } ;

/* Variables and functions */
 int efx_check_lm87 (struct efx_nic*,int) ; 

__attribute__((used)) static int sfn4112f_check_hw(struct efx_nic *efx)
{
	/* Mask out unused sensors */
	return efx_check_lm87(efx, ~0x48);
}