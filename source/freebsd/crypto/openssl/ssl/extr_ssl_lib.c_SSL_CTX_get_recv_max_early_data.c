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
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_3__ {int /*<<< orphan*/  recv_max_early_data; } ;
typedef  TYPE_1__ SSL_CTX ;

/* Variables and functions */

uint32_t SSL_CTX_get_recv_max_early_data(const SSL_CTX *ctx)
{
    return ctx->recv_max_early_data;
}