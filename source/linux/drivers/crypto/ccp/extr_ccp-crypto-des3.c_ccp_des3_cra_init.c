#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int reqsize; } ;
struct crypto_tfm {TYPE_3__ crt_ablkcipher; } ;
struct ccp_des3_req_ctx {int dummy; } ;
struct TYPE_4__ {scalar_t__ key_len; } ;
struct TYPE_5__ {TYPE_1__ des3; } ;
struct ccp_ctx {TYPE_2__ u; int /*<<< orphan*/  complete; } ;

/* Variables and functions */
 int /*<<< orphan*/  ccp_des3_complete ; 
 struct ccp_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 

__attribute__((used)) static int ccp_des3_cra_init(struct crypto_tfm *tfm)
{
	struct ccp_ctx *ctx = crypto_tfm_ctx(tfm);

	ctx->complete = ccp_des3_complete;
	ctx->u.des3.key_len = 0;

	tfm->crt_ablkcipher.reqsize = sizeof(struct ccp_des3_req_ctx);

	return 0;
}