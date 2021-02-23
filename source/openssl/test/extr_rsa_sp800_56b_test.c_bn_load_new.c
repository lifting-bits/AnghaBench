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
typedef  int /*<<< orphan*/  BIGNUM ;

/* Variables and functions */
 int /*<<< orphan*/  BN_bin2bn (unsigned char const*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * BN_new () ; 

__attribute__((used)) static BIGNUM *bn_load_new(const unsigned char *data, int sz)
{
    BIGNUM *ret = BN_new();
    if (ret != NULL)
        BN_bin2bn(data, sz, ret);
    return ret;
}