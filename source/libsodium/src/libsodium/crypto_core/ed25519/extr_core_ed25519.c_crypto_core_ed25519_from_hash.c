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

/* Variables and functions */
 int /*<<< orphan*/  ge25519_from_hash (unsigned char*,unsigned char const*) ; 

int
crypto_core_ed25519_from_hash(unsigned char *p, const unsigned char *h)
{
    ge25519_from_hash(p, h);

    return 0;
}