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
struct crypto_hash {int /*<<< orphan*/  t; int /*<<< orphan*/  s; } ;

/* Variables and functions */
 int /*<<< orphan*/  close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  os_free (struct crypto_hash*) ; 

__attribute__((used)) static void crypto_hash_deinit(struct crypto_hash *ctx)
{
	close(ctx->s);
	close(ctx->t);
	os_free(ctx);
}