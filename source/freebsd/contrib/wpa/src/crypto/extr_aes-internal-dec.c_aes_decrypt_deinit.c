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

/* Variables and functions */
 int /*<<< orphan*/  AES_PRIV_SIZE ; 
 int /*<<< orphan*/  os_free (void*) ; 
 int /*<<< orphan*/  os_memset (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void aes_decrypt_deinit(void *ctx)
{
	os_memset(ctx, 0, AES_PRIV_SIZE);
	os_free(ctx);
}