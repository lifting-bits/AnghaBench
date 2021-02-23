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
struct crypto_bignum {int dummy; } ;
typedef  int /*<<< orphan*/  BIGNUM ;

/* Variables and functions */
 int BN_rshift (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

int crypto_bignum_rshift(const struct crypto_bignum *a, int n,
			 struct crypto_bignum *r)
{
	/* Note: BN_rshift() does not modify the first argument even though it
	 * has not been marked const. */
	return BN_rshift((BIGNUM *) a, (BIGNUM *) r, n) == 1 ? 0 : -1;
}