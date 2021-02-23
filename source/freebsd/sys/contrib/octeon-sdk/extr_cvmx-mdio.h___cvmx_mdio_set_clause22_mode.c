#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ mode; } ;
struct TYPE_4__ {int /*<<< orphan*/  u64; TYPE_1__ s; } ;
typedef  TYPE_2__ cvmx_smix_clk_t ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_SMIX_CLK (int) ; 
 int /*<<< orphan*/  cvmx_read_csr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_write_csr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void __cvmx_mdio_set_clause22_mode(int bus_id)
{
    cvmx_smix_clk_t smi_clk;
    /* Put bus into clause 22 mode */
    smi_clk.u64 = cvmx_read_csr(CVMX_SMIX_CLK(bus_id));
    smi_clk.s.mode = 0;
    cvmx_write_csr(CVMX_SMIX_CLK(bus_id), smi_clk.u64);
}