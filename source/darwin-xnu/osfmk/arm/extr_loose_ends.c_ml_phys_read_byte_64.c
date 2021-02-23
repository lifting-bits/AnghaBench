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
typedef  int /*<<< orphan*/  pmap_paddr_t ;
typedef  scalar_t__ addr64_t ;

/* Variables and functions */
 unsigned int ml_phys_read_data (int /*<<< orphan*/ ,int) ; 

unsigned int ml_phys_read_byte_64(addr64_t paddr64)
{
        return ml_phys_read_data((pmap_paddr_t)paddr64, 1);
}