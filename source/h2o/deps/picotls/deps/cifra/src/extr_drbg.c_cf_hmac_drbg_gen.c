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
typedef  int /*<<< orphan*/  cf_hmac_drbg ;

/* Variables and functions */
 int /*<<< orphan*/  cf_hmac_drbg_gen_additional (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*,size_t) ; 

void cf_hmac_drbg_gen(cf_hmac_drbg *ctx, void *out, size_t nout)
{
  cf_hmac_drbg_gen_additional(ctx,
                              NULL, 0,
                              out, nout);
}