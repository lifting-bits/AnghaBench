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
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct octeon_hcd {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cvmx_read64_uint32 (int) ; 

__attribute__((used)) static inline u32 cvmx_usb_read_csr32(struct octeon_hcd *usb, u64 address)
{
	return cvmx_read64_uint32(address ^ 4);
}