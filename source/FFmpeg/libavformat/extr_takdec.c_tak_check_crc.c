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

/* Variables and functions */
 int /*<<< orphan*/  AV_CRC_24_IEEE ; 
 unsigned long av_crc (int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  av_crc_get_table (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned long tak_check_crc(unsigned long checksum, const uint8_t *buf,
                                   unsigned int len)
{
    return av_crc(av_crc_get_table(AV_CRC_24_IEEE), checksum, buf, len);
}