#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct crypto_async_request {int dummy; } ;
struct cryptd_hash_request_ctx {int /*<<< orphan*/  (* complete ) (TYPE_1__*,int) ;int /*<<< orphan*/  desc; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* complete ) (TYPE_1__*,int) ;} ;
struct ahash_request {TYPE_1__ base; int /*<<< orphan*/  result; } ;

/* Variables and functions */
 int EINPROGRESS ; 
 struct ahash_request* ahash_request_cast (struct crypto_async_request*) ; 
 struct cryptd_hash_request_ctx* ahash_request_ctx (struct ahash_request*) ; 
 int crypto_shash_final (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_bh_disable () ; 
 int /*<<< orphan*/  local_bh_enable () ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void cryptd_hash_final(struct crypto_async_request *req_async, int err)
{
	struct ahash_request *req = ahash_request_cast(req_async);
	struct cryptd_hash_request_ctx *rctx = ahash_request_ctx(req);

	if (unlikely(err == -EINPROGRESS))
		goto out;

	err = crypto_shash_final(&rctx->desc, req->result);

	req->base.complete = rctx->complete;

out:
	local_bh_disable();
	rctx->complete(&req->base, err);
	local_bh_enable();
}