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

/* Variables and functions */
 int nettle_digest_vector (int /*<<< orphan*/ *,size_t,int /*<<< orphan*/  const**,size_t const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nettle_md4 ; 

int md4_vector(size_t num_elem, const u8 *addr[], const size_t *len, u8 *mac)
{
	return nettle_digest_vector(&nettle_md4, num_elem, addr, len, mac);
}