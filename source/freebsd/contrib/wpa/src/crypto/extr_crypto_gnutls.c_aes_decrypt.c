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
typedef  void* gcry_cipher_hd_t ;

/* Variables and functions */
 int /*<<< orphan*/  gcry_cipher_decrypt (void*,int /*<<< orphan*/ *,int,int /*<<< orphan*/  const*,int) ; 

int aes_decrypt(void *ctx, const u8 *crypt, u8 *plain)
{
	gcry_cipher_hd_t hd = ctx;
	gcry_cipher_decrypt(hd, plain, 16, crypt, 16);
	return 0;
}