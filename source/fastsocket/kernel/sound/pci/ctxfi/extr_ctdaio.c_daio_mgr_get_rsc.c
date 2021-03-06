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
union daio_usage {int data; } ;
struct rsc_mgr {scalar_t__ rscs; } ;
typedef  enum DAIOTYP { ____Placeholder_DAIOTYP } DAIOTYP ;

/* Variables and functions */
 int ENOENT ; 

__attribute__((used)) static int daio_mgr_get_rsc(struct rsc_mgr *mgr, enum DAIOTYP type)
{
	if (((union daio_usage *)mgr->rscs)->data & (0x1 << type))
		return -ENOENT;

	((union daio_usage *)mgr->rscs)->data |= (0x1 << type);

	return 0;
}