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
typedef  int /*<<< orphan*/  aes_rval ;
typedef  int /*<<< orphan*/  aes_decrypt_ctx ;

/* Variables and functions */
 int /*<<< orphan*/  aes_decrypt_key (unsigned char const*,int,int /*<<< orphan*/ *) ; 

aes_rval aes_decrypt_key256(const unsigned char *key, aes_decrypt_ctx cx[1])
{
	return aes_decrypt_key(key, 32, cx);
}