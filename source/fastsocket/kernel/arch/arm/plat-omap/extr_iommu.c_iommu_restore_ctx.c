#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct iommu {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* restore_ctx ) (struct iommu*) ;} ;

/* Variables and functions */
 TYPE_1__* arch_iommu ; 
 int /*<<< orphan*/  stub1 (struct iommu*) ; 

void iommu_restore_ctx(struct iommu *obj)
{
	arch_iommu->restore_ctx(obj);
}