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
typedef  size_t uint32_t ;
typedef  int /*<<< orphan*/  r ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (size_t*,int /*<<< orphan*/ *,int) ; 
 size_t ntohl (size_t) ; 

__attribute__((used)) static uint32_t extract_u32(uint8_t *pkt, uint32_t off)
{
	uint32_t r;

	memcpy(&r, &pkt[off], sizeof(r));

	return ntohl(r);
}