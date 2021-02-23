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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  update_crc (int /*<<< orphan*/ *,scalar_t__,scalar_t__*) ; 

uint32_t
get_crc(uint8_t *p, uint32_t len)
{
	uint32_t crc;

	crc = 0;
	update_crc(p ,len , &crc);
	return crc;
}