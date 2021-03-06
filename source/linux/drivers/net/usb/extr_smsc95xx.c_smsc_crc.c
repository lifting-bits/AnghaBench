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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;

/* Variables and functions */
 int bitrev16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crc16 (int,int /*<<< orphan*/  const*,size_t) ; 

__attribute__((used)) static u32 smsc_crc(const u8 *buffer, size_t len, int filter)
{
	u32 crc = bitrev16(crc16(0xFFFF, buffer, len));
	return crc << ((filter % 2) * 16);
}