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
typedef  int uint32_t ;
struct ena_admin_get_feature_link_desc {int flags; } ;

/* Variables and functions */
 int ENA_ADMIN_GET_FEATURE_LINK_DESC_AUTONEG_MASK ; 

__attribute__((used)) static inline uint32_t get_ena_admin_get_feature_link_desc_autoneg(const struct ena_admin_get_feature_link_desc *p)
{
	return p->flags & ENA_ADMIN_GET_FEATURE_LINK_DESC_AUTONEG_MASK;
}