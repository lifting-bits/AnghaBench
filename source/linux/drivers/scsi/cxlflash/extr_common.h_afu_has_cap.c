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
struct afu {int interface_version; } ;

/* Variables and functions */
 int SISL_INTVER_CAP_SHIFT ; 

__attribute__((used)) static inline bool afu_has_cap(struct afu *afu, u64 cap)
{
	u64 afu_cap = afu->interface_version >> SISL_INTVER_CAP_SHIFT;

	return afu_cap & cap;
}