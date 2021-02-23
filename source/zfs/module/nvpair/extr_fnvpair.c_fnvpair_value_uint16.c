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
typedef  int /*<<< orphan*/  uint16_t ;
typedef  int /*<<< orphan*/  nvpair_t ;

/* Variables and functions */
 int /*<<< orphan*/  VERIFY0 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvpair_value_uint16 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

uint16_t
fnvpair_value_uint16(nvpair_t *nvp)
{
	uint16_t rv;
	VERIFY0(nvpair_value_uint16(nvp, &rv));
	return (rv);
}