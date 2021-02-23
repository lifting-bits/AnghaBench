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
typedef  int /*<<< orphan*/  chacha20poly1305_ctx ;
struct TYPE_2__ {int (* encrypt ) (int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t,void const*,void*) ;} ;

/* Variables and functions */
 TYPE_1__* fns () ; 
 int /*<<< orphan*/  info () ; 
 int stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t,void const*,void*) ; 

int	chacha20poly1305_encrypt(chacha20poly1305_ctx *ctx, size_t nbytes, const void *ptext, void *ctext)
{
    return fns()->encrypt(info(), ctx, nbytes, ptext, ctext);
}