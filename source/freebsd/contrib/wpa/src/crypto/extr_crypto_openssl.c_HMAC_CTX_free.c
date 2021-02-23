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
typedef  int /*<<< orphan*/  HMAC_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  HMAC_CTX_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bin_clear_free (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void HMAC_CTX_free(HMAC_CTX *ctx)
{
	if (!ctx)
		return;
	HMAC_CTX_cleanup(ctx);
	bin_clear_free(ctx, sizeof(*ctx));
}