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
typedef  int /*<<< orphan*/  int16_t ;
typedef  int /*<<< orphan*/  cvmx_fau_reg_16_t ;

/* Variables and functions */
 int /*<<< orphan*/  __cvmx_fau_store_address (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_write64_int16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void cvmx_fau_atomic_write16(cvmx_fau_reg_16_t reg, int16_t value)
{
    cvmx_write64_int16(__cvmx_fau_store_address(1, reg), value);
}