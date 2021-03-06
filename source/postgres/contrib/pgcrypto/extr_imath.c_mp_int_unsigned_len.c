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
typedef  int mp_result ;
typedef  int /*<<< orphan*/  mp_int ;

/* Variables and functions */
 int CHAR_BIT ; 
 int mp_int_count_bits (int /*<<< orphan*/ ) ; 

mp_result
mp_int_unsigned_len(mp_int z)
{
	mp_result	res = mp_int_count_bits(z);

	if (res <= 0)
		return res;

	int			bytes = (res + (CHAR_BIT - 1)) / CHAR_BIT;

	return bytes;
}