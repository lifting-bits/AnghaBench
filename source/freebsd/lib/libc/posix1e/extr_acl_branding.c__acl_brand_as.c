#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* acl_t ;
struct TYPE_4__ {int ats_brand; } ;

/* Variables and functions */
 int /*<<< orphan*/  _acl_brand_may_be (TYPE_1__*,int) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 

void
_acl_brand_as(acl_t acl, int brand)
{

	assert(_acl_brand_may_be(acl, brand));

	acl->ats_brand = brand;
}