#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  skey; int /*<<< orphan*/  num_rounds; } ;
typedef  TYPE_1__ br_aes_small_cbcenc_keys ;

/* Variables and functions */
 int /*<<< orphan*/  br_aes_small_encrypt (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char*) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,int) ; 

void
br_aes_small_cbcenc_run(const br_aes_small_cbcenc_keys *ctx,
	void *iv, void *data, size_t len)
{
	unsigned char *buf, *ivbuf;

	ivbuf = iv;
	buf = data;
	while (len > 0) {
		int i;

		for (i = 0; i < 16; i ++) {
			buf[i] ^= ivbuf[i];
		}
		br_aes_small_encrypt(ctx->num_rounds, ctx->skey, buf);
		memcpy(ivbuf, buf, 16);
		buf += 16;
		len -= 16;
	}
}