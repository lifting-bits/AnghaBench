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
struct TYPE_3__ {int /*<<< orphan*/  iv; } ;
union cvmx_pip_crc_ivx {scalar_t__ u64; TYPE_1__ s; } ;
struct TYPE_4__ {void* reflect; void* invres; } ;
union cvmx_pip_crc_ctlx {scalar_t__ u64; TYPE_2__ s; } ;
typedef  void* uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_PIP_CRC_CTLX (void*) ; 
 int /*<<< orphan*/  CVMX_PIP_CRC_IVX (void*) ; 
 int /*<<< orphan*/  OCTEON_CN38XX ; 
 int /*<<< orphan*/  OCTEON_CN58XX ; 
 scalar_t__ OCTEON_IS_MODEL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_write_csr (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void cvmx_pip_config_crc(uint64_t interface,
				       uint64_t invert_result, uint64_t reflect,
				       uint32_t initialization_vector)
{
	if (OCTEON_IS_MODEL(OCTEON_CN38XX) || OCTEON_IS_MODEL(OCTEON_CN58XX)) {
		union cvmx_pip_crc_ctlx config;
		union cvmx_pip_crc_ivx pip_crc_ivx;

		config.u64 = 0;
		config.s.invres = invert_result;
		config.s.reflect = reflect;
		cvmx_write_csr(CVMX_PIP_CRC_CTLX(interface), config.u64);

		pip_crc_ivx.u64 = 0;
		pip_crc_ivx.s.iv = initialization_vector;
		cvmx_write_csr(CVMX_PIP_CRC_IVX(interface), pip_crc_ivx.u64);
	}
}